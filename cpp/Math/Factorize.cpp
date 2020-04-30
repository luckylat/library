#include <iostream>
#include <map>
using namespace std;
//B
template<typename T>
pair<int,map<T,int>> Factorize(T n){
  map<T,int> a;
  int b = 0;
  
  for(T i = 2; n >= i*i; i++){
    while(!(n%i)){
      n/=i;
      a[i]++;
      b++;
    }
  }
  if(n != 1)a[n]++,b++;
  return make_pair(b,a);
}
//E
int main(){
  int q;cin>>q;
  map<long long ,int> k;
  for(int i = 0; q > i; i++){
    long long a;cin>>a;
    auto z=Factorize(a);
    
    cout << z.first;
    if(z.first!=0)cout << " ";
    for(auto p:z.second){
      for(int j = 0; p.second > j; j++){
        cout << p.first;
        z.first--;
        if(z.first)cout << " ";
      }
    }
    cout << endl;
  }
}