---
data:
  attributes:
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#!/usr/bin/env python3\n\n\"\"\"Add a common execution timeout to competitive-verifier\
      \ standalone tests.\"\"\"\n\nimport json\nimport sys\nfrom pathlib import Path\n\
      \n\nTIMEOUT = \"10s\"\nSTANDALONE_CACHE_MARKER = \".competitive-verifier/cache/standalone/\"\
      \n\n\ndef add_timeout(path: Path) -> int:\n    with path.open(encoding=\"utf-8\"\
      ) as file:\n        data = json.load(file)\n\n    wrapped = 0\n    for file_data\
      \ in data[\"files\"].values():\n        for verification in file_data.get(\"\
      verification\", []):\n            if verification.get(\"type\") != \"command\"\
      :\n                continue\n\n            command = verification.get(\"command\"\
      )\n            if not isinstance(command, str) or STANDALONE_CACHE_MARKER not\
      \ in command:\n                continue\n\n            verification[\"command\"\
      ] = [\n                \"timeout\",\n                \"--foreground\",\n   \
      \             \"--kill-after=1s\",\n                TIMEOUT,\n             \
      \   command,\n            ]\n            wrapped += 1\n\n    with path.open(\"\
      w\", encoding=\"utf-8\") as file:\n        json.dump(data, file, ensure_ascii=False,\
      \ indent=2)\n        file.write(\"\\n\")\n\n    return wrapped\n\n\ndef main()\
      \ -> None:\n    if len(sys.argv) != 2:\n        raise SystemExit(f\"usage: {Path(sys.argv[0]).name}\
      \ VERIFY_JSON\")\n\n    path = Path(sys.argv[1])\n    wrapped = add_timeout(path)\n\
      \    print(f\"Added {TIMEOUT} timeout to {wrapped} standalone tests in {path}\"\
      )\n\n\nif __name__ == \"__main__\":\n    main()\n"
    name: default
  isFailed: false
  isVerificationFile: false
  path: scripts/add_standalone_timeout.py
  pathExtension: py
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/add_standalone_timeout.py
layout: document
---
