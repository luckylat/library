#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/rho.cpp"

int main(){
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    long long n;cin>>n;
    Rho A(n); A.run();
    cout << A.factor.size();
    for(int i = 0; A.factor.size() > i; i++)cout << " " << A.factor[i];
    cout << endl;
  }
}
