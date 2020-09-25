---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links: []
  bundledCode: "#line 1 \"segtree/types/offline.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define IGNORE\n\ntemplate<typename T>\nstruct RangeCount{\n\
    \  struct BIT{\n    vector<T> dat;\n    BIT(){}\n    BIT(int n){dat.assign(++n,0);}\n\
    \    T sum(int k){\n      T res=0;\n      for(;k;k-=k&-k) res+=dat[k];\n     \
    \ return res;\n    }\n    void add(int k,T v){\n      for(++k;k<(int)dat.size();k+=k&-k)\
    \ dat[k]+=v;\n    }\n  };\n  int n;\n  vector<vector<int> > val;\n  vector<BIT>\
    \ dat;\n  RangeCount(){}\n  RangeCount(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n\
    \    val.assign(n<<1,vector<int>());\n    dat.reserve(n<<1);\n  }\n  void preupdate(int\
    \ a,int x){\n    a+=n;\n    while(a){\n      val[a].emplace_back(x);\n      a>>=1;\n\
    \    }\n  }\n  void build(){\n    for(int i=0;i<n*2;i++){\n      auto &v=val[i];\n\
    \      sort(v.begin(),v.end());\n      v.erase(unique(v.begin(),v.end()),v.end());\n\
    \      dat.emplace_back(v.size());\n    }\n  }\n  void update(int a,int x,int\
    \ z){\n    a+=n;\n    while(a){\n      auto &v=val[a];\n      int k=lower_bound(v.begin(),v.end(),x)-v.begin();\n\
    \      dat[a].add(k,z);\n      a>>=1;\n    }\n  }\n  T calc(int k,int x,int y){\n\
    \    auto &v=val[k];\n    int p=lower_bound(v.begin(),v.end(),x)-v.begin();\n\
    \    int q=lower_bound(v.begin(),v.end(),y)-v.begin();\n    return dat[k].sum(q)-dat[k].sum(p);\n\
    \  }\n  // [a, b) * [x, y)\n  T query(int a,int b,int x,int y){\n    T res=0;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) res+=calc(l++,x,y);\n\
    \      if(r&1) res+=calc(--r,x,y);\n    }\n    return res;\n  }\n};\n\nstruct\
    \ RangeTypes{\n  struct range{\n    int l,r,c;\n    range(){}\n    range(int l,int\
    \ r,int c):l(l),r(r),c(c){}\n    bool operator<(const range &a)const{\n      return\
    \ l<a.l;\n    }\n  };\n\n  int n,m,time;\n  vector<int> nxt,dat,upd;\n  set<int>\
    \ sx;\n\n  set<range> sr;\n  vector<set<range> > se;\n  RangeCount<int> rc;\n\
    \  using T = tuple<int, int, int>;\n  vector<T> mvs;\n\n  RangeTypes(int n_,int\
    \ m):m(m),time(0),se(m+1),rc(n_){\n    n=1;\n    while(n<n_) n<<=1;\n\n    nxt.assign(n,0);\n\
    \    iota(nxt.begin(),nxt.end(),1);\n\n    sr.emplace(0,n,m);\n    se[m].emplace(0,n,m);\n\
    \n    dat.assign(n<<1,0);\n    upd.assign(n<<1,0);\n\n    for(int i=0;i<n;i++)\
    \ rc.preupdate(i,i+1);\n  }\n\n  int get(int k) const{\n    k+=n;\n    int t=upd[k],c=dat[k];\n\
    \    while(k>>=1)\n      if(t<upd[k]) t=upd[k],c=dat[k];\n    return c;\n  }\n\
    \n  void reset(int a,int v){\n    if(nxt[a]==v) return;\n    mvs.emplace_back(a,nxt[a],v);\n\
    \    rc.preupdate(a,nxt[a]);\n    rc.preupdate(a,v);\n    nxt[a]=v;\n  }\n\n \
    \ void update(const int a,const int b,const int c){\n    assert(a<b);\n    assert(c<m);\n\
    \    time++;\n    // gather information\n    vector<int> vx,vc;\n    if(a) vc.emplace_back(get(a-1));\n\
    \    vc.emplace_back(c);\n    for(auto it=sx.lower_bound(a);it!=sx.end();++it){\n\
    \      if(*it>=b) break;\n      vx.emplace_back(*it);\n      vc.emplace_back(get(*it));\n\
    \    }\n    if(vx.empty()||vx.back()!=b-1){\n      vx.emplace_back(b-1);\n   \
    \   vc.emplace_back(get(b-1));\n    }\n\n    vector<range> vr;\n    {\n      auto\
    \ it=sr.lower_bound(range(a,0,0));\n      if(it!=sr.begin()) --it;\n      if(it->l<a&&a<it->r)\
    \ vr.emplace_back(*it);\n    }\n    for(auto it=sr.lower_bound(range(a,0,0));it!=sr.end();++it){\n\
    \      if(it->l>=b) break;\n      vr.emplace_back(*it);\n    }\n\n    // update\
    \ information\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) dat[l]=c,upd[l]=time,l++;\n\
    \      if(r&1) --r,dat[r]=c,upd[r]=time;\n    }\n\n    for(auto r:vr){\n     \
    \ sr.erase(r);\n      se[r.c].erase(r);\n    }\n    sr.emplace(a,b,c);\n    se[c].emplace(a,b,c);\n\
    \n    {\n      auto r=vr.front();\n      if(r.l<a){\n        sr.emplace(r.l,a,r.c);\n\
    \        se[r.c].emplace(r.l,a,r.c);\n      }\n    }\n    {\n      auto r=vr.back();\n\
    \      if(b<r.r){\n        sr.emplace(b,r.r,r.c);\n        se[r.c].emplace(b,r.r,r.c);\n\
    \      }\n    }\n\n    for(int x:vx){\n      if(x<b-1){\n        if(sx.count(x))\
    \ sx.erase(x);\n        reset(x,x+1);\n      }\n    }\n\n    {\n      int nb=n;\n\
    \      auto it=se[c].upper_bound(range(a,0,0));\n      if(it!=se[c].end()) nb=it->l;\n\
    \      reset(b-1,nb);\n      if(nb!=b) sx.emplace(b-1);\n    }\n\n    sort(vc.begin(),vc.end());\n\
    \    vc.erase(unique(vc.begin(),vc.end()),vc.end());\n    for(int x:vc){\n   \
    \   auto it=se[x].lower_bound(range(a,0,0));\n      if(it==se[x].begin()) continue;\n\
    \      int ny=(it==se[x].end()?n:it->l),y=(--it)->r-1;\n      reset(y,ny);\n \
    \     if(ny!=y+1) sx.emplace(y);\n    }\n  }\n\n  void count(const int a,const\
    \ int b){\n    mvs.emplace_back(-1,a,b);\n  }\n\n  vector<int> build(){\n    rc.build();\n\
    \    for(int i=0;i<n;i++) rc.update(i,i+1,1);\n    vector<int> res;\n    for(auto\
    \ mv:mvs){\n      int a,b,c;\n      tie(a,b,c)=mv;\n      if(~a){\n        rc.update(a,b,-1);\n\
    \        rc.update(a,c, 1);\n      }else{\n        res.emplace_back(rc.query(b,c,c,n<<1));\n\
    \      }\n    }\n    return res;\n  }\n};\n\ntemplate<typename T1,typename T2>\
    \ inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename T2>\
    \ inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\n\nstruct EulerTour{\n  int n,pos;\n\
    \  vector<vector<int> > G;\n  vector<int> ls,rs;\n\n  EulerTour(){}\n  EulerTour(int\
    \ n):n(n),G(n),ls(n),rs(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n\
    \    for(int u:G[v])\n      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\n  void\
    \ build(int r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n};\n\n//INSERT ABOVE HERE\n\
    signed main(){\n  int T;\n  scanf(\"%d\",&T);\n\n  for(int t=1;t<=T;t++){\n  \
    \  printf(\"Case #%d:\\n\",t);\n    int n;\n    scanf(\"%d\",&n);\n    EulerTour\
    \ et(n);\n    for(int i=1;i<n;i++){\n      int u,v;\n      scanf(\"%d %d\",&u,&v);\n\
    \      u--;v--;\n      et.add_edge(u,v);\n    }\n    vector<int> c(n);\n    for(int\
    \ i=0;i<n;i++) scanf(\"%d\",&c[i]);\n\n    et.build();\n    int q;\n    scanf(\"\
    %d\",&q);\n\n    if(n<=50000||q<=50000){\n      vector<int> val(n),used(n+1,-1);\n\
    \      for(int i=0;i<n;i++) val[et.ls[i]]=c[i];\n\n      for(int i=0;i<q;i++){\n\
    \        int type;\n        scanf(\"%d\",&type);\n        if(type==0){\n     \
    \     int u,w;\n          scanf(\"%d %d\",&u,&w);\n          u--;\n          for(int\
    \ j=et.ls[u];j<et.rs[u];j++) val[j]=w;\n        }\n        if(type==1){\n    \
    \      int u;\n          scanf(\"%d\",&u);\n          u--;\n          int cnt=0;\n\
    \          for(int j=et.ls[u];j<et.rs[u];j++){\n            if(used[val[j]]!=i)\
    \ cnt++;\n            used[val[j]]=i;\n          }\n          printf(\"%d\\n\"\
    ,cnt);\n        }\n      }\n      continue;\n    }\n\n    RangeTypes rt(n,n+10);\n\
    \    function<void(int, int)> dfs=\n      [&](int v,int p){\n        rt.update(et.ls[v],et.rs[v],c[v]);\n\
    \        for(int u:et.G[v])\n          if(p!=u) dfs(u,v);\n      };\n    dfs(0,\
    \ -1);\n\n    for(int i=0;i<q;i++){\n      int type;\n      scanf(\"%d\",&type);\n\
    \n      if(type==0){\n        int u,w;\n        scanf(\"%d %d\",&u,&w);\n    \
    \    u--;\n        rt.update(et.ls[u],et.rs[u],w);\n      }\n      if(type==1){\n\
    \        int u;\n        scanf(\"%d\",&u);\n        u--;\n        rt.count(et.ls[u],et.rs[u]);\n\
    \      }\n    }\n    auto vx=rt.build();\n    for(int x:vx) printf(\"%d\\n\",x);\n\
    \  }\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define IGNORE\n\ntemplate<typename\
    \ T>\nstruct RangeCount{\n  struct BIT{\n    vector<T> dat;\n    BIT(){}\n   \
    \ BIT(int n){dat.assign(++n,0);}\n    T sum(int k){\n      T res=0;\n      for(;k;k-=k&-k)\
    \ res+=dat[k];\n      return res;\n    }\n    void add(int k,T v){\n      for(++k;k<(int)dat.size();k+=k&-k)\
    \ dat[k]+=v;\n    }\n  };\n  int n;\n  vector<vector<int> > val;\n  vector<BIT>\
    \ dat;\n  RangeCount(){}\n  RangeCount(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n\
    \    val.assign(n<<1,vector<int>());\n    dat.reserve(n<<1);\n  }\n  void preupdate(int\
    \ a,int x){\n    a+=n;\n    while(a){\n      val[a].emplace_back(x);\n      a>>=1;\n\
    \    }\n  }\n  void build(){\n    for(int i=0;i<n*2;i++){\n      auto &v=val[i];\n\
    \      sort(v.begin(),v.end());\n      v.erase(unique(v.begin(),v.end()),v.end());\n\
    \      dat.emplace_back(v.size());\n    }\n  }\n  void update(int a,int x,int\
    \ z){\n    a+=n;\n    while(a){\n      auto &v=val[a];\n      int k=lower_bound(v.begin(),v.end(),x)-v.begin();\n\
    \      dat[a].add(k,z);\n      a>>=1;\n    }\n  }\n  T calc(int k,int x,int y){\n\
    \    auto &v=val[k];\n    int p=lower_bound(v.begin(),v.end(),x)-v.begin();\n\
    \    int q=lower_bound(v.begin(),v.end(),y)-v.begin();\n    return dat[k].sum(q)-dat[k].sum(p);\n\
    \  }\n  // [a, b) * [x, y)\n  T query(int a,int b,int x,int y){\n    T res=0;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) res+=calc(l++,x,y);\n\
    \      if(r&1) res+=calc(--r,x,y);\n    }\n    return res;\n  }\n};\n\nstruct\
    \ RangeTypes{\n  struct range{\n    int l,r,c;\n    range(){}\n    range(int l,int\
    \ r,int c):l(l),r(r),c(c){}\n    bool operator<(const range &a)const{\n      return\
    \ l<a.l;\n    }\n  };\n\n  int n,m,time;\n  vector<int> nxt,dat,upd;\n  set<int>\
    \ sx;\n\n  set<range> sr;\n  vector<set<range> > se;\n  RangeCount<int> rc;\n\
    \  using T = tuple<int, int, int>;\n  vector<T> mvs;\n\n  RangeTypes(int n_,int\
    \ m):m(m),time(0),se(m+1),rc(n_){\n    n=1;\n    while(n<n_) n<<=1;\n\n    nxt.assign(n,0);\n\
    \    iota(nxt.begin(),nxt.end(),1);\n\n    sr.emplace(0,n,m);\n    se[m].emplace(0,n,m);\n\
    \n    dat.assign(n<<1,0);\n    upd.assign(n<<1,0);\n\n    for(int i=0;i<n;i++)\
    \ rc.preupdate(i,i+1);\n  }\n\n  int get(int k) const{\n    k+=n;\n    int t=upd[k],c=dat[k];\n\
    \    while(k>>=1)\n      if(t<upd[k]) t=upd[k],c=dat[k];\n    return c;\n  }\n\
    \n  void reset(int a,int v){\n    if(nxt[a]==v) return;\n    mvs.emplace_back(a,nxt[a],v);\n\
    \    rc.preupdate(a,nxt[a]);\n    rc.preupdate(a,v);\n    nxt[a]=v;\n  }\n\n \
    \ void update(const int a,const int b,const int c){\n    assert(a<b);\n    assert(c<m);\n\
    \    time++;\n    // gather information\n    vector<int> vx,vc;\n    if(a) vc.emplace_back(get(a-1));\n\
    \    vc.emplace_back(c);\n    for(auto it=sx.lower_bound(a);it!=sx.end();++it){\n\
    \      if(*it>=b) break;\n      vx.emplace_back(*it);\n      vc.emplace_back(get(*it));\n\
    \    }\n    if(vx.empty()||vx.back()!=b-1){\n      vx.emplace_back(b-1);\n   \
    \   vc.emplace_back(get(b-1));\n    }\n\n    vector<range> vr;\n    {\n      auto\
    \ it=sr.lower_bound(range(a,0,0));\n      if(it!=sr.begin()) --it;\n      if(it->l<a&&a<it->r)\
    \ vr.emplace_back(*it);\n    }\n    for(auto it=sr.lower_bound(range(a,0,0));it!=sr.end();++it){\n\
    \      if(it->l>=b) break;\n      vr.emplace_back(*it);\n    }\n\n    // update\
    \ information\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) dat[l]=c,upd[l]=time,l++;\n\
    \      if(r&1) --r,dat[r]=c,upd[r]=time;\n    }\n\n    for(auto r:vr){\n     \
    \ sr.erase(r);\n      se[r.c].erase(r);\n    }\n    sr.emplace(a,b,c);\n    se[c].emplace(a,b,c);\n\
    \n    {\n      auto r=vr.front();\n      if(r.l<a){\n        sr.emplace(r.l,a,r.c);\n\
    \        se[r.c].emplace(r.l,a,r.c);\n      }\n    }\n    {\n      auto r=vr.back();\n\
    \      if(b<r.r){\n        sr.emplace(b,r.r,r.c);\n        se[r.c].emplace(b,r.r,r.c);\n\
    \      }\n    }\n\n    for(int x:vx){\n      if(x<b-1){\n        if(sx.count(x))\
    \ sx.erase(x);\n        reset(x,x+1);\n      }\n    }\n\n    {\n      int nb=n;\n\
    \      auto it=se[c].upper_bound(range(a,0,0));\n      if(it!=se[c].end()) nb=it->l;\n\
    \      reset(b-1,nb);\n      if(nb!=b) sx.emplace(b-1);\n    }\n\n    sort(vc.begin(),vc.end());\n\
    \    vc.erase(unique(vc.begin(),vc.end()),vc.end());\n    for(int x:vc){\n   \
    \   auto it=se[x].lower_bound(range(a,0,0));\n      if(it==se[x].begin()) continue;\n\
    \      int ny=(it==se[x].end()?n:it->l),y=(--it)->r-1;\n      reset(y,ny);\n \
    \     if(ny!=y+1) sx.emplace(y);\n    }\n  }\n\n  void count(const int a,const\
    \ int b){\n    mvs.emplace_back(-1,a,b);\n  }\n\n  vector<int> build(){\n    rc.build();\n\
    \    for(int i=0;i<n;i++) rc.update(i,i+1,1);\n    vector<int> res;\n    for(auto\
    \ mv:mvs){\n      int a,b,c;\n      tie(a,b,c)=mv;\n      if(~a){\n        rc.update(a,b,-1);\n\
    \        rc.update(a,c, 1);\n      }else{\n        res.emplace_back(rc.query(b,c,c,n<<1));\n\
    \      }\n    }\n    return res;\n  }\n};\n\ntemplate<typename T1,typename T2>\
    \ inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename T2>\
    \ inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\n\nstruct EulerTour{\n  int n,pos;\n\
    \  vector<vector<int> > G;\n  vector<int> ls,rs;\n\n  EulerTour(){}\n  EulerTour(int\
    \ n):n(n),G(n),ls(n),rs(n){}\n\n  void add_edge(int u,int v){\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void dfs(int v,int p){\n    ls[v]=pos++;\n\
    \    for(int u:G[v])\n      if(u!=p) dfs(u,v);\n    rs[v]=pos;\n  }\n\n  void\
    \ build(int r=0){\n    pos=0;\n    dfs(r,-1);\n  }\n\n};\n\n//INSERT ABOVE HERE\n\
    signed main(){\n  int T;\n  scanf(\"%d\",&T);\n\n  for(int t=1;t<=T;t++){\n  \
    \  printf(\"Case #%d:\\n\",t);\n    int n;\n    scanf(\"%d\",&n);\n    EulerTour\
    \ et(n);\n    for(int i=1;i<n;i++){\n      int u,v;\n      scanf(\"%d %d\",&u,&v);\n\
    \      u--;v--;\n      et.add_edge(u,v);\n    }\n    vector<int> c(n);\n    for(int\
    \ i=0;i<n;i++) scanf(\"%d\",&c[i]);\n\n    et.build();\n    int q;\n    scanf(\"\
    %d\",&q);\n\n    if(n<=50000||q<=50000){\n      vector<int> val(n),used(n+1,-1);\n\
    \      for(int i=0;i<n;i++) val[et.ls[i]]=c[i];\n\n      for(int i=0;i<q;i++){\n\
    \        int type;\n        scanf(\"%d\",&type);\n        if(type==0){\n     \
    \     int u,w;\n          scanf(\"%d %d\",&u,&w);\n          u--;\n          for(int\
    \ j=et.ls[u];j<et.rs[u];j++) val[j]=w;\n        }\n        if(type==1){\n    \
    \      int u;\n          scanf(\"%d\",&u);\n          u--;\n          int cnt=0;\n\
    \          for(int j=et.ls[u];j<et.rs[u];j++){\n            if(used[val[j]]!=i)\
    \ cnt++;\n            used[val[j]]=i;\n          }\n          printf(\"%d\\n\"\
    ,cnt);\n        }\n      }\n      continue;\n    }\n\n    RangeTypes rt(n,n+10);\n\
    \    function<void(int, int)> dfs=\n      [&](int v,int p){\n        rt.update(et.ls[v],et.rs[v],c[v]);\n\
    \        for(int u:et.G[v])\n          if(p!=u) dfs(u,v);\n      };\n    dfs(0,\
    \ -1);\n\n    for(int i=0;i<q;i++){\n      int type;\n      scanf(\"%d\",&type);\n\
    \n      if(type==0){\n        int u,w;\n        scanf(\"%d %d\",&u,&w);\n    \
    \    u--;\n        rt.update(et.ls[u],et.rs[u],w);\n      }\n      if(type==1){\n\
    \        int u;\n        scanf(\"%d\",&u);\n        u--;\n        rt.count(et.ls[u],et.rs[u]);\n\
    \      }\n    }\n    auto vx=rt.build();\n    for(int x:vx) printf(\"%d\\n\",x);\n\
    \  }\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/types/offline.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/types/offline.cpp
layout: document
redirect_from:
- /library/segtree/types/offline.cpp
- /library/segtree/types/offline.cpp.html
title: segtree/types/offline.cpp
---