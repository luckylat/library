#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/mod-int/mod-int.cpp"

#include "../../cpp/math/matrix.cpp"

int main(){
  int n;cin>>n;
  mat<mint> A(n,n);
  cin >> A;
  auto z = A.inv();
  if(!z.first) cout << -1 << endl;
  else cout << z.second << endl;
  return 0;
}

