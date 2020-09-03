---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/leastflow.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"dinic.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct LeastFlow{\n  Dinic<T, true> G;\n\
    \  int X,Y;\n  T sum;\n  LeastFlow(int n):G(n+2),X(n),Y(n+1),sum(0){}\n\n  void\
    \ add_edge(int from,int to,T low,T hgh){\n    assert(low<=hgh);\n    G.add_edge(from,to,hgh-low);\n\
    \    G.add_edge(X,to,low);\n    G.add_edge(from,Y,low);\n    sum+=low;\n  }\n\n\
    \  T flow(int s,int t){\n    T a=G.flow(X,Y);\n    T b=G.flow(s,Y);\n    T c=G.flow(X,t);\n\
    \    T d=G.flow(s,t);\n    return (b==c&&a+b==sum)?b+d:T(-1);\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - flow/dinic.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/dinic.cpp
    title: flow/dinic.cpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.test.cpp
    title: test/aoj/1615.test.cpp
  isVerificationFile: false
  path: flow/leastflow.cpp
  requiredBy: []
  timestamp: '2019-12-27 09:03:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/1615.test.cpp
documentation_of: flow/leastflow.cpp
layout: document
redirect_from:
- /library/flow/leastflow.cpp
- /library/flow/leastflow.cpp.html
title: flow/leastflow.cpp
---