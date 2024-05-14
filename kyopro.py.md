---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport os\n\n\ndef good_path(path):\n    return os.path.normcase(os.path.realpath(path))\n\
    \nclass include_file:\n    def __init__(self, file_path):\n        self.top =\
    \ os.getcwd()\n        self.file_path = good_path(file_path)\n        self.include_path\
    \ = good_path(os.path.dirname(\"C:/Users/include/\"))\n        self.id = {}\n\
    \        self.iid = []\n        self.graph = []\n\n    def query(self):\n    \
    \    with open(self.file_path, 'r') as file:\n            for line in file:\n\
    \                if not line.startswith('#include'):\n                    continue\n\
    \                included_file = line.split()[1].strip('\"<>\\n')\n          \
    \      if not included_file.startswith('kk2'):\n                    continue\n\
    \                included_file = good_path(os.path.join(self.include_path, included_file))\n\
    \                if included_file in self.id.keys():\n                    continue\n\
    \                self.id[included_file] = len(self.id)\n                self.iid.append(included_file)\n\
    \                self.graph.append([])\n                self.rec(included_file)\n\
    \        self.sorted = []\n        self.toposo()\n        self.erase_incude_file()\n\
    \        self.write_include_file()\n\n    def rec(self, cur):\n        print(cur)\n\
    \        with open(cur, 'r') as file:\n            for line in file:\n       \
    \         if not line.startswith('#include'):\n                    continue\n\
    \                if line.endswith('>\\n'):\n                    continue\n   \
    \             included_file = line.split()[1].strip('\"\\n')\n               \
    \ included_file = good_path(os.path.join(os.path.dirname(cur), included_file))\n\
    \                if included_file in self.id.keys():\n                    self.graph[self.id[cur]].append(self.id[included_file])\n\
    \                    continue\n                self.id[included_file] = len(self.id)\n\
    \                self.iid.append(included_file)\n                self.graph[self.id[cur]].append(self.id[included_file])\n\
    \                self.graph.append([])\n                self.rec(included_file)\n\
    \n    def toposo(self):\n        visited = [False] * len(self.graph)\n       \
    \ stack = []\n\n        def dfs(v):\n            visited[v] = True\n         \
    \   for neighbor in self.graph[v]:\n                if not visited[neighbor]:\n\
    \                    dfs(neighbor)\n            stack.append(v)\n\n        for\
    \ i in range(len(self.graph)):\n            if not visited[i]:\n             \
    \   dfs(i)\n\n        self.sorted = stack\n\n    def erase_incude_file(self):\n\
    \        with open(self.file_path, 'r') as file:\n            lines = file.readlines()\n\
    \        with open(self.file_path, 'w') as file:\n            for line in lines:\n\
    \                if not line.startswith('#include <kk2'):\n                  \
    \  file.write(line)\n\n    def write_include_file(self):\n        with open(self.file_path,\
    \ 'r') as file:\n            lines = file.readlines()\n        with open(self.file_path,\
    \ 'w') as file:\n            i = -1\n            for i, line in enumerate(lines):\n\
    \                if line.rstrip() == 'using namespace std;':\n               \
    \     i += 1\n                    break\n            tmp = self.all_include_files()\n\
    \            for line in reversed(tmp):\n                # print(len(tmp))\n \
    \               lines.insert(i, line)\n            # lines.insert(i, self.all_include_files())\n\
    \            for line in lines:\n                file.write(line)\n\n    def all_include_files(self)\
    \ -> list:\n        ret = []\n        for i in self.sorted:\n            with\
    \ open(self.iid[i], 'r') as file:\n                lines = file.readlines()\n\
    \                for line in lines:\n                    if line.startswith('#'):\n\
    \                        continue\n                    # print(line)\n       \
    \             ret.append(line)\n        return ret\n\n\n\ndef main(*args):\n \
    \   if len(args) == 1:\n        input_file = args[0]\n    else:\n        print('Usage:\
    \ kyopro <input_file>', file=sys.stderr)\n        exit(1)\n    # input_file =\
    \ './input.cpp'\n    a = include_file(input_file)\n    a.query()\n\nif __name__\
    \ == '__main__':\n    args = sys.argv[1:]\n    main(*args)\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro.py
layout: document
redirect_from:
- /library/kyopro.py
- /library/kyopro.py.html
title: kyopro.py
---
