#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//B
template<typename T>
struct BIT{//1_Indexed
  int n;
  vector<T> bit;
  BIT(int n_):n(n_+1),bit(n,0){}

  T sum(int a){
  int ret = 0;
  for(int i = a; i > 0; i -= i & -i) ret += bit[i];
  return ret;
  }

  void add(int a,int w){
    for(int i = a; i <= n; i += i & -i)bit[i] += w;
  }

  T query(int l,int r){
    return sum(l-1)-sum(r-1);
  }

};
//E


int main(){//ARC075-E
  long long n,m;cin>>n>>m;
  vector<long long> a(n);
  for(int i = 0; n > i; i++){
    cin>>a[i];
    a[i] -= m;
  }
  vector<long long> b(n+1);
  vector<long long> c(n+1);
  b[0] = 0;
  c[0] = 0;
  for(int i = 1; n >= i; i++){
    b[i] = b[i-1]+a[i-1];
    c[i] = b[i];
  }
  sort(c.begin(),c.end());
  c.erase(unique(c.begin(),c.end()),c.end());
  vector<long long> d(c.size());
  for(int i = 0; n >= i; i++){
    auto z = lower_bound(c.begin(),c.end(),b[i]) - c.begin();
    d[z]++;
  }
  BIT<int> e(c.size());
  for(int i = 1; c.size() >= i; i++){
    e.add(i,d[i-1]);
  }
  long long ans = 0;
  for(int i = 0; n >= i; i++){
    
    auto z = lower_bound(c.begin(),c.end(),b[i]) - c.begin();
    ans += max(0,e.sum(c.size())-e.sum(z)-1);
    //cout <<sum(z) << endl;
    //cout <<":" << b[i] << " " << z << endl;
    e.add(z+1,-1);
  }
  cout << ans << endl;

}