import sys
import os


def good_path(path):
    return os.path.normcase(os.path.realpath(path))

class include_file:
    def __init__(self, file_path):
        self.top = os.getcwd()
        self.file_path = good_path(file_path)
        self.include_path = good_path(os.path.dirname("C:/Users/include/"))
        self.id = {}
        self.iid = []
        self.graph = []

    def query(self):
        self.rec(self.file_path)
        self.sorted = self.toposo()
        self.erase_incude_file()
        self.write_include_file()

    def rec(self, cur):
        # print(cur)
        flag = self.file_path == cur
        with open(cur, 'r') as file:
            for line in file:
                if not line.startswith('#include'):
                    continue

                if flag:
                    included_file = line.split()[1].strip('"<>\n')
                    if not included_file.startswith('kk2'):
                        continue
                else:
                    if line.endswith('>\n'):
                        continue
                    included_file = line.split()[1].strip('"\n')

                if flag:
                    included_file = good_path(os.path.join(self.include_path, included_file))
                else:
                    included_file = good_path(os.path.join(os.path.dirname(cur), included_file))

                if included_file in self.id.keys():
                    if not flag:
                        self.graph[self.id[cur]].append(self.id[included_file])
                    continue
                self.id[included_file] = len(self.id)
                self.iid.append(included_file)
                if not flag:
                    self.graph[self.id[cur]].append(self.id[included_file])
                self.graph.append([])
                self.rec(included_file)

    def toposo(self):
        visited = [False] * len(self.graph)
        stack = []

        def dfs(v):
            visited[v] = True
            for neighbor in self.graph[v]:
                if not visited[neighbor]:
                    dfs(neighbor)
            stack.append(v)

        for i in range(len(self.graph)):
            if not visited[i]:
                dfs(i)

        return stack

    def erase_incude_file(self):
        with open(self.file_path, 'r') as file:
            lines = file.readlines()
        with open(self.file_path, 'w') as file:
            for line in lines:
                if not line.startswith('#include <kk2'):
                    file.write(line)

    def write_include_file(self):
        with open(self.file_path, 'r') as file:
            lines = file.readlines()
        with open(self.file_path, 'w') as file:
            tmp = self.all_include_files()
            for line in reversed(tmp):
                # print(len(tmp))
                lines.insert(0, line)
            # lines.insert(i, self.all_include_files())
            for line in lines:
                file.write(line)

    def all_include_files(self) -> list:
        ret = []
        for i in self.sorted:
            with open(self.iid[i], 'r') as file:
                lines = file.readlines()
                for line in lines:
                    if (line.startswith('#include') and
                        not line.endswith('>\n')):
                        continue
                    # print(line)
                    ret.append(line)
        return ret


def main(*args):
    if len(args) == 1:
        input_file = args[0]
    else:
        print('Usage: kyopro <input_file>', file=sys.stderr)
        exit(1)
    # input_file = './input.cpp'
    a = include_file(input_file)
    a.query()

if __name__ == '__main__':
    args = sys.argv[1:]
    main(*args)
