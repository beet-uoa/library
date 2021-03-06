// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1338

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/fraction.cpp"
#undef call_from_test

using ll = long long;
using frac = fraction<ll>;

int H,h,m,s;
void print(frac f){
  int t=f.num/(f.den*60);
  cout<<(t%(60*H))/60<<" ";
  cout<<(t%60)<<" ";
  cout<<(f.num)%(f.den*60)<<" "<<f.den<<endl;
}

frac norm2(frac a){
  if(a.num==0) return frac(0,1);
  while(a.num<0) a.num+=a.den;
  while(a.num>=a.den) a.num-=a.den;
  ll tmp=__gcd(a.num,a.den);
  return frac(a.num/tmp,a.den/tmp);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  while(cin>>H>>h>>m>>s,H){
    const frac base(h*3600+m*60+s,1);
    const frac vh(1,3600*H),vm(1,3600),vs(1,60);
    frac t(max(h*3600+m*60+s-100,0),1);
    while(1){
      frac x=norm2(t*vh);
      frac y=norm2(t*vm);
      frac z=norm2(t*vs);
      if(y<x) y=y+frac(1,1);
      if(z<x) z=z+frac(1,1);
      frac ans(10000000,1);
      {
        frac t1=frac(1,1)-(z-x);
        frac t2=z-y;
        frac tmp=t+(t1-t2)/(vs*2-(vh+vm));
        if(base<=tmp){
          frac a=norm2(tmp*vh);
          frac b=norm2(tmp*vm);
          frac c=norm2(tmp*vs);
          if(b<a) b=b+frac(1,1);
          if(c<a) c=c+frac(1,1);
          if(b<c){
            t1=frac(1,1)-(c-a);
            t2=c-b;
            if(a!=b&&b!=c&&c!=a&&t1==t2)
              ans=min(ans,tmp);
          }
        }
      }
      {
        frac t1=z-x;
        frac t2=y-z;
        frac tmp=t+(t2-t1)/(vs*2-(vh+vm));
        if(base<=tmp){
          frac a=norm2(tmp*vh);
          frac b=norm2(tmp*vm);
          frac c=norm2(tmp*vs);
          if(b<a) b=b+frac(1,1);
          if(c<a) c=c+frac(1,1);
          if(b>c){
            t1=c-a;
            t2=b-c;
            if(a!=b&&b!=c&&c!=a&&t1==t2)
              ans=min(ans,tmp);
          }
        }
      }
      if(ans!=frac(10000000,1)){
        print(ans);
        break;
      }
      t=t+frac(1,1);
    }
  }
  return 0;
}
