import sys
import os
import pyperclip # type: ignore
import re

def good_path(path):
    return os.path.normcase(os.path.realpath(path))

class include_file:
    def __init__(self, file_path, include_path):
        self.file_path = good_path(file_path)
        self.include_path = good_path(include_path)

    def expand(self):
        self.expand_all_include_files()
        self.clip()

    def expand_rollback(self):
        backup_lines = self.backup()
        self.expand_all_include_files()
        self.clip()
        self.rollback(backup_lines)

    def get_inlude_path(self, line, cur_file_path):
        included_file = ''
        line = re.sub(r'\s+', '', line)
        if line.startswith('#include<kk2/'):
            included_file = line[8:].strip('<>')
            included_file = good_path(os.path.join(self.include_path, included_file))
        elif line.startswith('#include"'):
            included_file = line[8:].strip('"')
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
                    else:
                        lines.append(f'// {line}')

            lines.append("\n")

        with open(self.file_path, 'r', encoding="utf-8") as file:
            for line in file:
                included_file_path = self.get_inlude_path(line, self.file_path)
                if included_file_path == '':
                    lines.append(line)
                    continue
                rec(included_file_path)
                if included_file_path != '':
                    lines.append(f"// {line}\n")

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
    input_file = ''
    rollback = True
    if len(args) == 1:
        input_file = args[0]
    elif len(args) == 2:
        input_file = args[0]
        if args[1] == '--no-rollback':
            rollback = False
        elif args[1] == '--rollback':
            rollback = True
        else:
            print(f'bad option: {args[1]}', file=sys.stderr)
            exit(1)
    else:
        print('Usage: my-expand <input_file>', file=sys.stderr)
        exit(1)
    # input_file = './input.cpp'
    included_path = "C:/Users/include/"
    a = include_file(input_file, included_path)
    if (rollback):
        a.expand_rollback()
    else:
        a.expand()

if __name__ == '__main__':
    args = sys.argv[1:]
    main(*args)
