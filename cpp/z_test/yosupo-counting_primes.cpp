#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/meissel-lehhmer.cpp"


int main(){
  long long n;;cin>>n;
  MeisselLehmer P(n);
  cout << P.count() << endl;
}
