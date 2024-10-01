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
    \ file_path):\n        self.file_path = good_path(file_path)\n        self.include_path\
    \ = good_path(\"C:/Users/include/\")\n\n    def expand(self):\n        self.expand_all_include_files()\n\
    \n    def expand_clip(self):\n        backup_lines = self.backup()\n        self.expand_all_include_files()\n\
    \        self.clip()\n        self.rollback(backup_lines)\n\n    def get_inlude_path(self,\
    \ line, cur_file_path):\n        included_file = ''\n        if line.startswith('#include\
    \ <kk2'):\n            included_file = line.split()[1].strip('<>\\n')\n      \
    \      included_file = good_path(os.path.join(self.include_path, included_file))\n\
    \        elif line.startswith('#include<kk2'):\n            included_file = line[8:].strip('<>\\\
    n')\n            included_file = good_path(os.path.join(self.include_path, included_file))\n\
    \        elif line.startswith('#include \"'):\n            included_file = line.split()[1].strip('\"\
    \\n')\n            included_file = good_path(os.path.join(os.path.dirname(cur_file_path),\
    \ included_file))\n        elif line.startswith('#include\"'):\n            included_file\
    \ = line[8:].strip('\"\\n')\n            included_file = good_path(os.path.join(os.path.dirname(cur_file_path),\
    \ included_file))\n        return included_file\n\n    def expand_all_include_files(self):\n\
    \        file_path_set = set()\n        lines = []\n        def rec(cur_file_path):\n\
    \            if file_path_set.__contains__(cur_file_path):\n                return\n\
    \            file_path_set.add(cur_file_path)\n\n            with open(cur_file_path,\
    \ 'r', encoding=\"utf-8\") as file:\n                for line in file:\n     \
    \               included_file_path = self.get_inlude_path(line, cur_file_path)\n\
    \                    if included_file_path == '':\n                        continue\n\
    \n                    rec(included_file_path)\n\n            with open(cur_file_path,\
    \ 'r', encoding=\"utf-8\") as file:\n                for line in file:\n     \
    \               inlcluded_file_path = self.get_inlude_path(line, cur_file_path)\n\
    \                    if inlcluded_file_path == '':\n                        lines.append(line)\n\
    \n            lines.append(\"\\n\")\n\n        with open(self.file_path, 'r',\
    \ encoding=\"utf-8\") as file:\n            for line in file:\n              \
    \  included_file_path = self.get_inlude_path(line, self.file_path)\n         \
    \       if included_file_path == '':\n                    lines.append(line)\n\
    \                    continue\n                rec(included_file_path)\n\n   \
    \     lines.append('\\n// converted!!\\n')\n        with open(self.file_path,\
    \ 'w', encoding=\"utf-8\") as file:\n            file.write(''.join(lines))\n\n\
    \    def backup(self):\n        with open(self.file_path, 'r', encoding=\"utf-8\"\
    ) as file:\n            lines = file.readlines()\n        return lines\n\n   \
    \ def rollback(self, lines):\n        with open(self.file_path, 'w', encoding=\"\
    utf-8\") as file:\n            file.write('')\n            for line in lines:\n\
    \                file.write(line)\n\n    def clip(self):\n        with open(self.file_path,\
    \ 'r', encoding=\"utf-8\") as file:\n            pyperclip.copy(file.read())\n\
    \n\ndef main(*args):\n    if len(args) == 1:\n        input_file = args[0]\n \
    \   else:\n        print('Usage: my-expand <input_file>', file=sys.stderr)\n \
    \       exit(1)\n    # input_file = './input.cpp'\n    a = include_file(input_file)\n\
    \    a.expand_clip()\n\nif __name__ == '__main__':\n    args = sys.argv[1:]\n\
    \    main(*args)\n"
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
