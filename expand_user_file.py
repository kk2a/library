import sys
import os
import pyperclip


def good_path(path):
    return os.path.normcase(os.path.realpath(path))

class include_file:
    def __init__(self, file_path):
        self.file_path = good_path(file_path)
        self.include_path = good_path("C:/Users/include/")

    def expand(self):
        self.expand_all_include_files()

    def expand_clip(self):
        backup_lines = self.backup()
        self.expand_all_include_files()
        self.clip()
        self.rollback(backup_lines)

    def get_inlude_path(self, line, cur_file_path):
        included_file = ''
        if line.startswith('#include <kk2'):
            included_file = line.split()[1].strip('<>\n')
            included_file = good_path(os.path.join(self.include_path, included_file))
        elif line.startswith('#include<kk2'):
            included_file = line[8:].strip('<>\n')
            included_file = good_path(os.path.join(self.include_path, included_file))
        elif line.startswith('#include "'):
            included_file = line.split()[1].strip('"\n')
            included_file = good_path(os.path.join(os.path.dirname(cur_file_path), included_file))
        elif line.startswith('#include"'):
            included_file = line[8:].strip('"\n')
            included_file = good_path(os.path.join(os.path.dirname(cur_file_path), included_file))
        return included_file

    def expand_all_include_files(self):
        file_path_set = set()
        lines = []
        def rec(cur_file_path):
            if file_path_set.__contains__(cur_file_path):
                return
            file_path_set.add(cur_file_path)

            with open(cur_file_path, 'r', encoding="utf-8") as file:
                for line in file:
                    included_file_path = self.get_inlude_path(line, cur_file_path)
                    if included_file_path == '':
                        continue

                    rec(included_file_path)

            with open(cur_file_path, 'r', encoding="utf-8") as file:
                for line in file:
                    inlcluded_file_path = self.get_inlude_path(line, cur_file_path)
                    if inlcluded_file_path == '':
                        lines.append(line)

            lines.append("\n")

        with open(self.file_path, 'r', encoding="utf-8") as file:
            for line in file:
                included_file_path = self.get_inlude_path(line, self.file_path)
                if included_file_path == '':
                    lines.append(line)
                    continue
                rec(included_file_path)

        lines.append('\n// converted!!\n')
        with open(self.file_path, 'w', encoding="utf-8") as file:
            file.write(''.join(lines))

    def backup(self):
        with open(self.file_path, 'r', encoding="utf-8") as file:
            lines = file.readlines()
        return lines

    def rollback(self, lines):
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
    a.expand_clip()

if __name__ == '__main__':
    args = sys.argv[1:]
    main(*args)
