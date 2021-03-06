#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656
//BEGIN CUT HERE
struct RangeToRange{
  const int n;
  int ptr;
  RangeToRange(int n):n(n),ptr(3*n){}

  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)

  // map [3n, 4n) -> [n, 2n)
  template<typename F>
  void add_edge(int u,int v,F f){
    if(3*n<=u and u<4*n) u-=2*n;
    f(u,v);
  }

  template<typename F>
  void init(F f){
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      add_edge(0*n+i,0*n+l,f);
      add_edge(0*n+i,0*n+r,f);
      add_edge(2*n+l,2*n+i,f);
      add_edge(2*n+r,2*n+i,f);
    }
  }

  // [l1, r1) -> [l2, r2)
  template<typename F,typename G>
  void add_edge(int l1,int r1,int l2,int r2,F f,G g){
    int k=ptr++;
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) add_edge(2*n+(l1++),k,f);
      if(r1&1) add_edge(2*n+(--r1),k,f);
    }
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) g(k,l2++);
      if(r2&1) g(k,--r2);
    }
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return ptr;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
