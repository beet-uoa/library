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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/longestcommonprefix.cpp
* category: string


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [string/suffixarray.cpp](suffixarray.cpp.html)
* :heavy_check_mark: [tools/chminmax.cpp](../tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../tools/fastio.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/2711.test.cpp](../../verify/test/aoj/2711.test.cpp.html)
* :heavy_check_mark: [test/aoj/3063.test.cpp](../../verify/test/aoj/3063.test.cpp.html)
* :heavy_check_mark: [test/aoj/3112.test.cpp](../../verify/test/aoj/3112.test.cpp.html)
* :heavy_check_mark: [test/yosupo/number_of_substrings.test.cpp](../../verify/test/yosupo/number_of_substrings.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "suffixarray.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct LongestCommonPrefix{
  SuffixArray sa;

  vector<int> ht;
  vector< vector<int> > dat;
  LongestCommonPrefix(string &s):sa(s){
    int n=s.size();
    vector<int> lcp(n,0);

    int t=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
      int j=sa[sa.rev[i]-1];
      if(t>0) t--;
      for(;j+t<n&&i+t<n;t++){
        if(sa.s[j+t]!=sa.s[i+t]) break;
      }
      lcp[sa.rev[i]-1]=t;
    }

    int h=1;
    while((1<<h)<n) h++;
    dat.assign(h,vector<int>(n));
    ht.assign(n+1,0);
    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=lcp[j];
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<n;j++)
        dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+p,n-1)]);
  }

  // a, b are indices for suffix array
  int query(int a,int b){
    assert(a!=b);
    if(a>b) swap(a,b);
    int l=b-a;
    return min(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  // a, b are indices for string
  int lcp(int a,int b){
    return query(sa.rev[a],sa.rev[b]);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed ARC060_F(){
  string s;
  cin>>s;
  int n=s.size();
  {
    string t(s);
    t.erase(unique(t.begin(),t.end()),t.end());
    if(t.size()==1u){
      cout<<n<<endl<<1<<endl;
      return 0;
    }
  }

  vector<vector<int> > v(n+1);
  for(int i=1;i<=n;i++)
    for(int j=i+i;j<=n;j+=i)
      v[j].emplace_back(i);

  LongestCommonPrefix lcp(s);
  auto check=
    [&](int l,int r)->int{
      for(int x:v[r-l])
        if(lcp.lcp(l,l+x)>=r-l-x) return 0;
      return 1;
    };

  if(check(0,n)){
    cout<<1<<endl<<1<<endl;
    return 0;
  }

  int ans=0;
  for(int i=1;i<n;i++)
    ans+=check(0,i)&&check(i,n);

  cout<<2<<endl<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/arc060/tasks/arc060_d
*/

signed main(){
  ARC060_F();
  return 0;
};
#endif

```
{% endraw %}

[Back to top page](../../index.html)
