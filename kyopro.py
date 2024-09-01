import sys
import os
import pyperclip


def good_path(path):
    return os.path.normcase(os.path.realpath(path))

class include_file:
    def __init__(self, file_path):
        self.top = os.getcwd()
        self.file_path = good_path(file_path)
        self.include_path = good_path(os.path.dirname("C:/Users/include/"))
        self.backup_lines = []

    def query(self):
        self.backup_lines = self.backup()
        file_id, get_file_path = self.find_and_memo()
        file_id, get_file_path, adj_array = self.get_dag(file_id, get_file_path)
        # print(adj_array)
        self.expand_all_include_files(file_id, get_file_path, adj_array)
        self.clip()
        self.rollback()

    # 一週目で自分のファイルを探し．それらをメモする
    def find_and_memo(self):
        # ファイル名をキーにして，ファイルに数字を割り当てる
        file_id = {}
        # 数字をみて，ファイル名を取得する
        get_file_path = []

        with open(self.file_path, 'r', encoding="utf-8") as file:
            for line in file:
                if not line.startswith('#include <kk2'):
                    continue
                included_file = line.split()[1].strip('<>\n')
                included_file = good_path(os.path.join(self.include_path, included_file))
                if included_file in file_id.keys():
                    continue
                file_id[included_file] = len(file_id)
                get_file_path.append(included_file)
        return file_id, get_file_path

    # id をもとに，隣接リストを作成する
    def get_dag(self, file_id, get_file_path):
        adj_array = [[] for _ in range(len(file_id))]
        def rec(cur):
            with open(cur, 'r', encoding="utf-8") as file:
                for line in file:
                    if not line.startswith('#include'):
                        continue
                    included_file = line.split()[1]
                    if included_file.startswith('<'):
                        continue
                    included_file = included_file.strip('"\n')
                    included_file = good_path(os.path.join(os.path.dirname(cur), included_file))
                    if included_file in file_id.keys():
                        adj_array[file_id[cur]].append(file_id[included_file])
                        continue
                    file_id[included_file] = len(file_id)
                    get_file_path.append(included_file)
                    adj_array.append([])
                    adj_array[file_id[cur]].append(file_id[included_file])
                    rec(included_file)

        file_num = len(get_file_path)
        for i in range(file_num):
            rec(get_file_path[i])

        return file_id, get_file_path, adj_array

    def expand_all_include_files(self, file_id, get_file_path, adj_array):
        used = [False] * len(file_id)
        lines = []
        def rec(cur_id):
            if used[cur_id]:
                return
            used[cur_id] = True
            for next in adj_array[cur_id]:
                rec(next)

            with open(get_file_path[cur_id], 'r', encoding="utf-8") as file:
                for line in file:
                    if not line.startswith('#include "'):
                        lines.append(line)

            lines.append("\n")

        with open(self.file_path, 'r', encoding="utf-8") as file:
            for line in file:
                if not line.startswith('#include <kk2'):
                    lines.append(line)
                else:
                    included_file = line.split()[1].strip('<>\n')
                    included_file = good_path(os.path.join(self.include_path, included_file))
                    rec(file_id[included_file])

        lines.append('\n// converted!!\n')
        with open(self.file_path, 'w', encoding="utf-8") as file:
            file.write(''.join(lines))

    def backup(self):
        with open(self.file_path, 'r', encoding="utf-8") as file:
            lines = file.readlines()
        return lines

    def rollback(self):
        lines = self.backup_lines
        with open(self.file_path, 'w', encoding="utf-8") as file:
            file.write('')
            for line in lines:
                file.write(line)

    def clip(self):
        with open(self.file_path, 'r', encoding="utf-8") as file:
            pyperclip.copy(file.read())


def main(*args):
    if len(args) == 1:
        input_file = args[0]
    else:
        print('Usage: my-expand <input_file>', file=sys.stderr)
        exit(1)
    # input_file = './input.cpp'
    a = include_file(input_file)
    a.query()

if __name__ == '__main__':
    args = sys.argv[1:]
    main(*args)
