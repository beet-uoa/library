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


# :heavy_check_mark: test/aoj/GRL_5_A.linkcuttree.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A)


## Dependencies
* :heavy_check_mark: [linkcuttree/base.cpp](../../../library/linkcuttree/base.cpp.html)
* :heavy_check_mark: [linkcuttree/farthest.cpp](../../../library/linkcuttree/farthest.cpp.html)
* :heavy_check_mark: [tools/chminmax.cpp](../../../library/tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/chminmax.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/farthest.cpp"
#undef call_from_test

signed main(){
  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs;
  vector<LCT::Node*> es;
  vs.reserve(1e5+100);
  es.reserve(1e5+100);

  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,0);

  for(int i=1;i<n;i++){
    int s,t,w;
    cin>>s>>t>>w;
    es[i]=lct.create(n+i,w);
    lct.evert(vs[s]);
    lct.evert(vs[t]);
    lct.link(es[i],vs[s]);
    lct.link(es[i],vs[t]);
  }

  int ans=0;
  for(int i=0;i<n;i++){
    lct.evert(vs[i]);
    chmax(ans,vs[i]->ld);
  }

  cout<<ans<<endl;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)
