#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/mod-int.cpp"
#include "../../cpp/math/matrix.cpp"

int main(){
  int n,m,k;cin>>n>>m>>k;
  mat<mint> A(n,m),B(m,k);
  for(int i = 0; n > i; i++){
    for(int j = 0; m > j; j++){
      cin>>A[i][j];
    }
  }
  for(int i = 0; m > i; i++){
    for(int j = 0; k > j; j++){
      cin>>B[i][j];
    }
  }
  cout << A*B << endl;
}

