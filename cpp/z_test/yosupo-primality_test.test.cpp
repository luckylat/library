#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/miller-rabin.cpp"

int main(){
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    long long n;cin>>n;
    cout << (MillerRabinCheck(n) ? "Yes" : "No") << endl;
  }
}
