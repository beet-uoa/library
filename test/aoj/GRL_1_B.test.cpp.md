---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/drop.cpp
    title: tools/drop.cpp
  - icon: ':heavy_check_mark:'
    path: graph/bellmanford.cpp
    title: graph/bellmanford.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"tools/drop.cpp\"\n\n#line 3 \"tools/drop.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 1 \"graph/bellmanford.cpp\"\n\n#line 3 \"graph/bellmanford.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct\
    \ BellmanFord{\n  static constexpr T INF = numeric_limits<T>::max();\n\n  struct\
    \ edge{\n    int u,v;\n    T w;\n    edge(){}\n    edge(int u,int v,T w):u(u),v(v),w(w){}\n\
    \  };\n\n  int n;\n  vector< vector<int> > G;\n  vector<int> used,reach;\n  BellmanFord(int\
    \ n):n(n),G(n),used(n,0),reach(n,1){}\n\n  vector<edge> es;\n  void add_edge(int\
    \ u,int v,T c){\n    es.emplace_back(u,v,c);\n    G[u].emplace_back(v);\n  }\n\
    \n  vector<T> build(int from,int &neg_loop){\n    vector<T> ds(n,INF);\n    ds[from]=0;\n\
    \    for(int j=0;j<n;j++){\n      bool update=0;\n      for(auto e:es){\n    \
    \    if(!reach[e.u]||!reach[e.v]||ds[e.u]==INF) continue;\n        if(ds[e.v]>ds[e.u]+e.w){\n\
    \          ds[e.v]=ds[e.u]+e.w;\n          update=1;\n        }\n      }\n   \
    \   if(!update) break;\n      if(j==n-1){\n        neg_loop=1;\n        return\
    \ ds;\n      }\n    }\n    neg_loop=0;\n    return ds;\n  }\n\n  void dfs(int\
    \ v){\n    if(used[v]) return;\n    used[v]=1;\n    for(int u:G[v]) dfs(u);\n\
    \  }\n\n  T shortest_path(int from,int to,int &neg_loop){\n    for(int i=0;i<n;i++){\n\
    \      fill(used.begin(),used.end(),0);\n      dfs(i);\n      reach[i]=used[to];\n\
    \    }\n    return build(from,neg_loop)[to];\n  }\n};\ntemplate<typename T>\n\
    constexpr T BellmanFord<T>::INF;\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 9 \"test/aoj/GRL_1_B.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m,r;\n  cin>>n>>m>>r;\n\n  BellmanFord<int> G(n);\n  for(int i=0;i<m;i++){\n\
    \    int a,b,c;\n    cin>>a>>b>>c;\n    G.add_edge(a,b,c);\n  }\n\n  int neg_loop;\n\
    \  auto res=G.build(r,neg_loop);\n  if(neg_loop) drop(\"NEGATIVE CYCLE\");\n\n\
    \  for(int x:res){\n    if(x==BellmanFord<int>::INF) cout<<\"INF\\n\";\n    else\
    \ cout<<x<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../tools/drop.cpp\"\n#include \"../../graph/bellmanford.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m,r;\n  cin>>n>>m>>r;\n\n  BellmanFord<int> G(n);\n  for(int i=0;i<m;i++){\n\
    \    int a,b,c;\n    cin>>a>>b>>c;\n    G.add_edge(a,b,c);\n  }\n\n  int neg_loop;\n\
    \  auto res=G.build(r,neg_loop);\n  if(neg_loop) drop(\"NEGATIVE CYCLE\");\n\n\
    \  for(int x:res){\n    if(x==BellmanFord<int>::INF) cout<<\"INF\\n\";\n    else\
    \ cout<<x<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - tools/drop.cpp
  - graph/bellmanford.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:21:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---