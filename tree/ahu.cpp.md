---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1613.test.cpp
    title: test/aoj/1613.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Talk.pdf
  bundledCode: "#line 1 \"tree/ahu.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n// http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Talk.pdf\n\
    //BEGIN CUT HERE\nstruct AHU{\n  static map<vector<int>, int> I;\n  vector< vector<int>\
    \ > G;\n  AHU(int n):G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  int dfs(int v,int p){\n    vector<int> hs;\n\
    \    for(int u:G[v])\n      if(u!=p) hs.emplace_back(dfs(u,v));\n    sort(hs.begin(),hs.end());\n\
    \n    int sz=I.size();\n    if(!I.count(hs)) I[hs]=sz;\n    return I[hs];\n  }\n\
    \n  int build(int r=0){\n    return dfs(r,-1);\n  }\n};\nmap<vector<int>, int>\
    \ AHU::I;\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n// http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Talk.pdf\n\
    //BEGIN CUT HERE\nstruct AHU{\n  static map<vector<int>, int> I;\n  vector< vector<int>\
    \ > G;\n  AHU(int n):G(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  int dfs(int v,int p){\n    vector<int> hs;\n\
    \    for(int u:G[v])\n      if(u!=p) hs.emplace_back(dfs(u,v));\n    sort(hs.begin(),hs.end());\n\
    \n    int sz=I.size();\n    if(!I.count(hs)) I[hs]=sz;\n    return I[hs];\n  }\n\
    \n  int build(int r=0){\n    return dfs(r,-1);\n  }\n};\nmap<vector<int>, int>\
    \ AHU::I;\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/ahu.cpp
  requiredBy: []
  timestamp: '2020-10-14 14:10:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1613.test.cpp
documentation_of: tree/ahu.cpp
layout: document
title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u5224\u5B9A"
---

## できること
与えられた根付き木の決定的なハッシュ値を求める

一般の木について同型性判定を行う場合は、まず木の中心や重心を求め、それらを根にすればよい

## 計算量
$O(N \log N)$