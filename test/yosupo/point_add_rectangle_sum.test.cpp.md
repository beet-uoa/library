---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: vector/compress.cpp
    title: vector/compress.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/count/dynamic_offline.cpp
    title: segtree/count/dynamic_offline.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"vector/compress.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"vector/compress.cpp\"\nusing namespace std;\n\
    #endif\n\n//BEGIN CUT HERE\ntemplate<typename V>\nV compress(V vs){\n  sort(vs.begin(),vs.end());\n\
    \  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n  return vs;\n}\ntemplate<typename\
    \ T>\nmap<T, int> dict(const vector<T> &vs){\n  map<T, int> res;\n  for(int i=0;i<(int)vs.size();i++)\n\
    \    res[vs[i]]=i;\n  return res;\n}\nmap<char, int> dict(const string &s){\n\
    \  return dict(vector<char>(s.begin(),s.end()));\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"segtree/count/dynamic_offline.cpp\"\
    \n\n#line 3 \"segtree/count/dynamic_offline.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Key,typename T>\nstruct RangeCount{\n  struct\
    \ BIT{\n    vector<T> dat;\n    BIT(){}\n    BIT(int n){dat.assign(++n,0);}\n\
    \    T sum(int k){\n      T res=0;\n      for(;k;k-=k&-k) res+=dat[k];\n     \
    \ return res;\n    }\n    void add(int k,T v){\n      for(++k;k<(int)dat.size();k+=k&-k)\
    \ dat[k]+=v;\n    }\n  };\n  int n;\n  vector< vector<Key> > val;\n  vector<BIT>\
    \ dat;\n  RangeCount(){}\n  RangeCount(int n):n(n){\n    val.assign(n<<1,vector<Key>());\n\
    \    dat.reserve(n<<1);\n  }\n  void preupdate(int a,Key x){\n    a+=n;\n    while(a){\n\
    \      val[a].emplace_back(x);\n      a>>=1;\n    }\n  }\n  void build(){\n  \
    \  for(int i=0;i<n*2;i++){\n      auto &vs=val[i];\n      sort(vs.begin(),vs.end());\n\
    \      vs.erase(unique(vs.begin(),vs.end()),vs.end());\n      dat.emplace_back(vs.size());\n\
    \    }\n  }\n  void update(int a,Key x,T z){\n    a+=n;\n    while(a){\n     \
    \ auto &vs=val[a];\n      int k=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \      dat[a].add(k,z);\n      a>>=1;\n    }\n  }\n  T calc(int k,Key x,Key y){\n\
    \    auto &vs=val[k];\n    int p=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \    int q=lower_bound(vs.begin(),vs.end(),y)-vs.begin();\n    return dat[k].sum(q)-dat[k].sum(p);\n\
    \  }\n  // [a, b) * [x, y)\n  T query(int a,int b,Key x,Key y){\n    T res=0;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) res+=calc(l++,x,y);\n\
    \      if(r&1) res+=calc(--r,x,y);\n    }\n    return res;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n//END CUT HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 9 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\
    \n#undef call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  vector<int>\
    \ xs(n+q),ys(n+q),ws(n+q);\n  for(int i=0;i<n;i++)\n    cin>>xs[i]>>ys[i]>>ws[i];\n\
    \n  vector<int> ts(q);\n  vector<int> ls(q),ds(q),rs(q),us(q);\n  for(int i=0;i<q;i++){\n\
    \    cin>>ts[i];\n    if(ts[i]==0) cin>>xs[n+i]>>ys[n+i]>>ws[n+i];\n    if(ts[i]==1)\
    \ cin>>ls[i]>>ds[i]>>rs[i]>>us[i];\n  }\n\n  auto vs=compress(xs);\n  auto idx=\n\
    \    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};\n\n  using\
    \ ll = long long;\n  RangeCount<int, ll> seg(vs.size());\n\n  for(int i=0;i<n;i++)\n\
    \    seg.preupdate(idx(xs[i]),ys[i]);\n\n  for(int i=0;i<q;i++)\n    if(ts[i]==0)\
    \ seg.preupdate(idx(xs[n+i]),ys[n+i]);\n\n  seg.build();\n\n  for(int i=0;i<n;i++)\n\
    \    seg.update(idx(xs[i]),ys[i],ws[i]);\n\n  for(int i=0;i<q;i++){\n    if(ts[i]==0)\
    \ seg.update(idx(xs[n+i]),ys[n+i],ws[n+i]);\n    if(ts[i]==1) cout<<seg.query(idx(ls[i]),idx(rs[i]),ds[i],us[i])<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../vector/compress.cpp\"\n#include \"../../segtree/count/dynamic_offline.cpp\"\
    \n#undef call_from_test\n\n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  vector<int>\
    \ xs(n+q),ys(n+q),ws(n+q);\n  for(int i=0;i<n;i++)\n    cin>>xs[i]>>ys[i]>>ws[i];\n\
    \n  vector<int> ts(q);\n  vector<int> ls(q),ds(q),rs(q),us(q);\n  for(int i=0;i<q;i++){\n\
    \    cin>>ts[i];\n    if(ts[i]==0) cin>>xs[n+i]>>ys[n+i]>>ws[n+i];\n    if(ts[i]==1)\
    \ cin>>ls[i]>>ds[i]>>rs[i]>>us[i];\n  }\n\n  auto vs=compress(xs);\n  auto idx=\n\
    \    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};\n\n  using\
    \ ll = long long;\n  RangeCount<int, ll> seg(vs.size());\n\n  for(int i=0;i<n;i++)\n\
    \    seg.preupdate(idx(xs[i]),ys[i]);\n\n  for(int i=0;i<q;i++)\n    if(ts[i]==0)\
    \ seg.preupdate(idx(xs[n+i]),ys[n+i]);\n\n  seg.build();\n\n  for(int i=0;i<n;i++)\n\
    \    seg.update(idx(xs[i]),ys[i],ws[i]);\n\n  for(int i=0;i<q;i++){\n    if(ts[i]==0)\
    \ seg.update(idx(xs[n+i]),ys[n+i],ws[n+i]);\n    if(ts[i]==1) cout<<seg.query(idx(ls[i]),idx(rs[i]),ds[i],us[i])<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - vector/compress.cpp
  - segtree/count/dynamic_offline.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-02 21:26:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.test.cpp
---