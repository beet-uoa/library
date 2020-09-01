---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/cartesian_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/cartesian_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 11:09:34+09:00


* see: <a href="https://judge.yosupo.jp/problem/cartesian_tree">https://judge.yosupo.jp/problem/cartesian_tree</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/cartesiantree.cpp.html">datastructure/cartesiantree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/cartesiantree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto ps=cartesian_tree(as);
  for(int i=0;i<n;i++){
    if(i) cout<<' ';
    cout<<(ps[i]<0?i:ps[i]);
  }
  cout<<newl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/cartesian_tree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "datastructure/cartesiantree.cpp"

#ifndef call_from_test
#line 5 "datastructure/cartesiantree.cpp"
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T>
vector<int> cartesian_tree(const vector<T> &vs){
  int n=vs.size();
  vector<int> ps(n,-1),ls(n,-1),rs(n,-1);
  int cur=0;
  for(int i=1;i<n;i++){
    if(vs[cur]<=vs[i]){
      rs[cur]=i;
      ps[i]=cur;
      cur=i;
      continue;
    }
    while(~ps[cur] and vs[i]<vs[ps[cur]]) cur=ps[cur];
    ps[i]=ps[cur];
    if(~ps[i]) rs[ps[i]]=i;
    ls[i]=cur;
    ps[cur]=i;
    cur=i;
  }
  return ps;
}
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/cartesian_tree.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto ps=cartesian_tree(as);
  for(int i=0;i<n;i++){
    if(i) cout<<' ';
    cout<<(ps[i]<0?i:ps[i]);
  }
  cout<<newl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
