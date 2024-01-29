#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/convolution.cpp"

int main(){
  int na,nb;cin>>na>>nb;
  vector<mint> A(na), B(nb);
  for(int i = 0; na > i; i++)cin>>A[i];
  for(int i = 0; nb > i; i++)cin>>B[i];
  auto C = convolution(A, B);
  for(int i = 0; C.size() > i; i++){
    cout << C[i] << " \n"[i+1 == C.size()];
  }
}
