#include "../data-structure/binary-indexed-tree.cpp"
#include "sieve-of-eratosthenes.cpp"
#include "exactsqrt.cpp"

struct MeisselLehmer{
  long long N;
  long long alpha;
  SieveEratos sieve;
  BIT<int> varphiTable;
  struct d{
    long long m,b;
    int cof;
    bool operator<(const d x)const{
      if(m == x.m) return b < x.b;
      return m < x.m;
    }
  };
  vector<d> varphiQueue; 
  MeisselLehmer(long long n): N(n){
    alpha = ceil(pow(N, 0.34));
    sieve.set(N/alpha+10);
    sieve.generate_invprime();
    sieve.generate_minfactor();
  }
  long long varphiLoop(long long n, long long a, int cof = 1){
    if(a == 0){
      return n;
    }else{
      if(n/sieve.primes[a-1] <= N/alpha){
        if(n/sieve.primes[a-1] >= 2){
          varphiQueue.push_back({n/sieve.primes[a-1], a-1, cof*-1});
          return varphiLoop(n, a-1, cof);
        }else{
          return varphiLoop(n, a-1, cof) - varphiLoop(n/sieve.primes[a-1], a-1, cof*-1);
        } 
      }else{
        return varphiLoop(n, a-1, cof) - varphiLoop(n/sieve.primes[a-1], a-1, cof*-1);
      }
    }
  }

  long long varphi(long long n, long long a){
    varphiTable.set(N/alpha+1);
    long long val = varphiLoop(n,a);
    sort(varphiQueue.begin(), varphiQueue.end());
    int cur = 0;
    for(int i = 2; N/alpha >= i; i++){
      varphiTable.add(sieve.invprimes[sieve.minp[i]], 1);
      while(cur < varphiQueue.size() && varphiQueue[cur].m == i){
        val += varphiQueue[cur].cof * (varphiQueue[cur].m - varphiTable.query(1, varphiQueue[cur].b+1));
        cur++;
      }
    }
    varphiQueue.clear();
    return val;
  }

  long long P2(long long n, long long a){
    long long val = 0;
    int cur = sieve.primes.size()-1;
    for(int i = a; n/sieve.primes[a-1] > sieve.primes[i]; i++){
      while((sieve.primes[cur] > n / sieve.primes[i] || (n%sieve.primes[i] == 0 && sieve.primes[cur] == n/sieve.primes[i]))){
        cur--;
      }
      if(cur < i)break;
      val += cur-i+1;
    }
    return val;
  }


  long long count(long long n = -1){
    if(n == -1)n = N;
    long long prevN = N;
    N = n;
    alpha = ceil(pow(N, 0.34));
    if(N < 2)return 0;
    else if(N < 3)return 1;
    long long val = varphi(N, alpha) + alpha-1 - P2(N, alpha);
    N = prevN;
    return val;
  }
};

