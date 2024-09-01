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
  code: "import sys\nimport os\nimport pyperclip\n\n\ndef good_path(path):\n    return\
    \ os.path.normcase(os.path.realpath(path))\n\nclass include_file:\n    def __init__(self,\
    \ file_path):\n        self.top = os.getcwd()\n        self.file_path = good_path(file_path)\n\
    \        self.include_path = good_path(os.path.dirname(\"C:/Users/include/\"))\n\
    \        self.backup_lines = []\n\n    def query(self):\n        self.backup_lines\
    \ = self.backup()\n        file_id, get_file_path = self.find_and_memo()\n   \
    \     file_id, get_file_path, adj_array = self.get_dag(file_id, get_file_path)\n\
    \        # print(adj_array)\n        self.expand_all_include_files(file_id, get_file_path,\
    \ adj_array)\n        self.clip()\n        self.rollback()\n\n    # \u4E00\u9031\
    \u76EE\u3067\u81EA\u5206\u306E\u30D5\u30A1\u30A4\u30EB\u3092\u63A2\u3057\uFF0E\
    \u305D\u308C\u3089\u3092\u30E1\u30E2\u3059\u308B\n    def find_and_memo(self):\n\
    \        # \u30D5\u30A1\u30A4\u30EB\u540D\u3092\u30AD\u30FC\u306B\u3057\u3066\uFF0C\
    \u30D5\u30A1\u30A4\u30EB\u306B\u6570\u5B57\u3092\u5272\u308A\u5F53\u3066\u308B\
    \n        file_id = {}\n        # \u6570\u5B57\u3092\u307F\u3066\uFF0C\u30D5\u30A1\
    \u30A4\u30EB\u540D\u3092\u53D6\u5F97\u3059\u308B\n        get_file_path = []\n\
    \n        with open(self.file_path, 'r', encoding=\"utf-8\") as file:\n      \
    \      for line in file:\n                if not line.startswith('#include <kk2'):\n\
    \                    continue\n                included_file = line.split()[1].strip('<>\\\
    n')\n                included_file = good_path(os.path.join(self.include_path,\
    \ included_file))\n                if included_file in file_id.keys():\n     \
    \               continue\n                file_id[included_file] = len(file_id)\n\
    \                get_file_path.append(included_file)\n        return file_id,\
    \ get_file_path\n\n    # id \u3092\u3082\u3068\u306B\uFF0C\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u3092\u4F5C\u6210\u3059\u308B\n    def get_dag(self, file_id, get_file_path):\n\
    \        adj_array = [[] for _ in range(len(file_id))]\n        def rec(cur):\n\
    \            with open(cur, 'r', encoding=\"utf-8\") as file:\n              \
    \  for line in file:\n                    if not line.startswith('#include'):\n\
    \                        continue\n                    included_file = line.split()[1]\n\
    \                    if included_file.startswith('<'):\n                     \
    \   continue\n                    included_file = included_file.strip('\"\\n')\n\
    \                    included_file = good_path(os.path.join(os.path.dirname(cur),\
    \ included_file))\n                    if included_file in file_id.keys():\n \
    \                       adj_array[file_id[cur]].append(file_id[included_file])\n\
    \                        continue\n                    file_id[included_file]\
    \ = len(file_id)\n                    get_file_path.append(included_file)\n  \
    \                  adj_array.append([])\n                    adj_array[file_id[cur]].append(file_id[included_file])\n\
    \                    rec(included_file)\n\n        file_num = len(get_file_path)\n\
    \        for i in range(file_num):\n            rec(get_file_path[i])\n\n    \
    \    return file_id, get_file_path, adj_array\n\n    def expand_all_include_files(self,\
    \ file_id, get_file_path, adj_array):\n        used = [False] * len(file_id)\n\
    \        lines = []\n        def rec(cur_id):\n            if used[cur_id]:\n\
    \                return\n            used[cur_id] = True\n            for next\
    \ in adj_array[cur_id]:\n                rec(next)\n\n            with open(get_file_path[cur_id],\
    \ 'r', encoding=\"utf-8\") as file:\n                for line in file:\n     \
    \               if not line.startswith('#include \"'):\n                     \
    \   lines.append(line)\n\n            lines.append(\"\\n\")\n\n        with open(self.file_path,\
    \ 'r', encoding=\"utf-8\") as file:\n            for line in file:\n         \
    \       if not line.startswith('#include <kk2'):\n                    lines.append(line)\n\
    \                else:\n                    included_file = line.split()[1].strip('<>\\\
    n')\n                    included_file = good_path(os.path.join(self.include_path,\
    \ included_file))\n                    rec(file_id[included_file])\n\n       \
    \ lines.append('\\n// converted!!\\n')\n        with open(self.file_path, 'w',\
    \ encoding=\"utf-8\") as file:\n            file.write(''.join(lines))\n\n   \
    \ def backup(self):\n        with open(self.file_path, 'r', encoding=\"utf-8\"\
    ) as file:\n            lines = file.readlines()\n        return lines\n\n   \
    \ def rollback(self):\n        lines = self.backup_lines\n        with open(self.file_path,\
    \ 'w', encoding=\"utf-8\") as file:\n            file.write('')\n            for\
    \ line in lines:\n                file.write(line)\n\n    def clip(self):\n  \
    \      with open(self.file_path, 'r', encoding=\"utf-8\") as file:\n         \
    \   pyperclip.copy(file.read())\n\n\ndef main(*args):\n    if len(args) == 1:\n\
    \        input_file = args[0]\n    else:\n        print('Usage: my-expand <input_file>',\
    \ file=sys.stderr)\n        exit(1)\n    # input_file = './input.cpp'\n    a =\
    \ include_file(input_file)\n    a.query()\n\nif __name__ == '__main__':\n    args\
    \ = sys.argv[1:]\n    main(*args)\n"
  dependsOn: []
  isVerificationFile: false
  path: expand_user_file.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expand_user_file.py
layout: document
redirect_from:
- /library/expand_user_file.py
- /library/expand_user_file.py.html
title: expand_user_file.py
---
