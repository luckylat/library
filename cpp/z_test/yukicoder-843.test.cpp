#define PROBLEM "https://yukicoder.me/problems/no/843"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/sieve-of-eratosthenes.cpp"


int main(){
  long long n;cin>>n;
  SieveEratos A(n+1);
  int ans = 0;
  for(int i = 0; n+2 >= A.primes[i]*A.primes[i]; i++){
    if(A[A.primes[i]*A.primes[i]-2])ans+=2;
    if(!i)ans--;
  }
  cout << ans << endl;
}