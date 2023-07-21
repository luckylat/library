#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/sieve-of-eratosthenes.cpp"


int main(){
  int n,a,b;cin>>n>>a>>b;
  SieveEratos P(n);
  cout << P.primes.size() << " " << (P.primes.size()-b+a-1)/a << endl;
  for(int i = b; P.primes.size() > i; i+=a){
    if(i != b)cout << " ";
    cout << P.primes[i];
  }
  cout << endl;
  return 0;
}
