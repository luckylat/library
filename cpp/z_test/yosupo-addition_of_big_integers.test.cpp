#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/big-int.cpp"

void solve(){
  BigInt A,B;cin>>A>>B;
  cout << A+B << endl;
}

int main(){
  int T;cin>>T;
  for(int i = 0; T > i; i++){
    solve();
  }
}
