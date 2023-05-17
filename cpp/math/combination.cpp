template <int mod>
struct Combination {
  long long n_max;
  vector<long long> fac, inv, finv;
  Combination(int n):n_max(n), fac(n+1,1), inv(n+1,1), finv(n+1,1){
    for(int i = 2; n > i; i++){
      fac[i] = (fac[i-1]*i)%mod;
      inv[i] = mod-((inv[mod%i]*(mod/i))%mod);
      finv[i] = (finv[i-1]*inv[i])%mod;
    }
  }

  long long C(int n, int r){
    if(n < r)return 0;
    if(n > n_max)return 0;
    return (((fac[n]*finv[r])%mod)*finv[n-r])%mod;
  }

  long long P(int n, int r){
    if(n < r)return 0;
    if(n > n_max)return 0;
    return (fac[n]*finv[n-r])%mod;
  }

  long long H(int n, int r){
    if(n==0 && r==0)return 1;
    return C(n+r-1, r);
  }
};
using comb = Combination<MOD>;
