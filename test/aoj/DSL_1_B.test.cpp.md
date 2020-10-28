---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/weightedunionfind.cpp
    title: datastructure/weightedunionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    datastructure/weightedunionfind.cpp\"\n\n#line 3 \"datastructure/weightedunionfind.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate <typename T>\nstruct\
    \ WeightedUnionFind{\n  vector<int> rs,ps;\n  vector<T> ws;\n\n  WeightedUnionFind(int\
    \ n):rs(n,1),ps(n),ws(n,T(0)){\n    iota(ps.begin(),ps.end(),0);\n  }\n\n  int\
    \ find(int x){\n    if(x==ps[x]) return x;\n    int t=find(ps[x]);\n    ws[x]+=ws[ps[x]];\n\
    \    return ps[x]=t;\n  }\n\n  T weight(int x){\n    find(x);\n    return ws[x];\n\
    \  }\n\n  bool same(int x,int y){\n    return find(x)==find(y);\n  }\n\n  void\
    \ unite(int x,int y,T w){\n    w+=weight(x);\n    w-=weight(y);\n    x=find(x);y=find(y);\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y),w=-w;\n    rs[x]+=rs[y];\n\
    \    ps[y]=x;\n    ws[y]=w;\n  }\n\n  T diff(int x,int y){\n    return weight(y)-weight(x);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n\
    }\n#endif\n#line 8 \"test/aoj/DSL_1_B.test.cpp\"\n#undef call_from_test\n\nint\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  WeightedUnionFind<int> wuf(n);\n\n  for(int i=0;i<q;i++){\n    int t,x,y,z;\n\
    \    cin>>t>>x>>y;\n    if(t){\n      if(wuf.same(x,y)) cout<<wuf.diff(x,y)<<\"\
    \\n\";\n      else cout<<\"?\\n\";\n    }else{\n      cin>>z;\n      wuf.unite(x,y,z);\n\
    \    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/weightedunionfind.cpp\"\n#undef call_from_test\n\nint\
    \ main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\
    \  WeightedUnionFind<int> wuf(n);\n\n  for(int i=0;i<q;i++){\n    int t,x,y,z;\n\
    \    cin>>t>>x>>y;\n    if(t){\n      if(wuf.same(x,y)) cout<<wuf.diff(x,y)<<\"\
    \\n\";\n      else cout<<\"?\\n\";\n    }else{\n      cin>>z;\n      wuf.unite(x,y,z);\n\
    \    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/weightedunionfind.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---