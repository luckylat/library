#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//B
template<typename T>
struct lazyBIT{//1_Indexed
  int n;
  vector<T> bit;
  vector<T> range;
  lazyBIT(int n_):n(n_+1),bit(n,0),range(n,0){}

  T sum(int a){
    T ret = 0;
    for(int i = a; i > 0; i -= i & -i) ret += bit[i];
    return ret;
  }
  T rangesum(int a){
    T ret = 0;
    for(int i = a; i > 0; i -= i & -i) ret += range[i];
    return ret;
  }

  void add(int a,T w){
    for(int i = a; i <= n; i += i & -i)bit[i] += w;
  }
  void rangeadd(int x,int y,T w){// x < y
    y++;
    for(int i = x; i <= n; i += i & -i)range[i] += w;
    for(int i = y; i <= n; i += i & -i)range[i] -= w;
  }

  T query(int l,int r){
    if(r==1){
      return sum(l)+rangesum(l);
    }
    return sum(l)-sum(r-1)+rangesum(l);
  }


};
//E
int main(){//https://yukicoder.me/submissions/440699
  int n,q;cin>>n>>q;
  vector<long long> A(n);
  vector<long long> B(n);
  for(int i = 0; n > i; i++){
    cin>>A[i];
    B[i] = 0;
  }
  lazyBIT<long long> Z(n);
  for(int i = 0; q > i; i++){
    char c;long long x,y;cin>>c>>x>>y;
    if(c == 'A'){
      //bit[x]+=y;
      if(Z.query(x,x)){
        int m = Z.query(x,x);
        B[x-1] += m*A[x-1];
        Z.add(x,m*-1);
      }
      A[x-1] += y;
    }else{
      Z.rangeadd(x,y,1);
    }
  }
  for(int j = 0; n > j; j++){
    cout << B[j]+Z.query(j+1,j+1)*A[j];
    if(j+1 != n)cout << " ";
  }
  cout << endl;
}