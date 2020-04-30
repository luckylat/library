#include <vector>
#include <iostream>
using namespace std;
//S
struct SieveEratos{
  vector<bool> t;
  SieveEratos(int n):t(n+1,true){
    t[0] = t[1] = false;
    for(int i = 2; n >= i; i++){
      if(t[i]){
        for(int j = i+i; n >= j; j+=i){
          t[j] = false;
        }
      }
    }
  }
  bool operator[](int x){return t[x];}
};
//E
int main(){//https://atcoder.jp/contests/abc084/submissions/9536037
  SieveEratos a(100010);
  vector<int> r;
  r.push_back(0);
  for(int i = 1; 100000 >= i; i++)r.push_back(r[r.size()-1]+(a[i] && a[(i+1)/2]));
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    int y,z;cin>>y>>z;
    cout << r[z]-r[y-1] << endl;
  }

}
