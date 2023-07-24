#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/quotients.cpp"

int main(){
  long long n;cin>>n;
  auto z = quotients(n);
  cout << z.size() << endl;
  for(int i = 0; z.size() > i; i++){
    cout << z[i] << " \n"[i+1 == z.size()];
  }
}
