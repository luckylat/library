struct SieveEratos{
  int N;
  vector<int> minp;
  vector<bool> t;
  vector<int> primes;
  map<int,int> invprimes;
  SieveEratos(){}
  SieveEratos(int n):N(n+1){
    generate();
  }
  void set(int n){
    N = n+1;
    generate();
  }
  void generate(){
    t.assign(N, true);
    t[0] = t[1] = false;
    for(int i = 2; N > i; i++){
      if(t[i]){
        primes.emplace_back(i);
        for(int j = i+i; N > j; j+=i){
          t[j] = false;
        }
      }
    } 
  }
  void generate_invprime(){
    for(size_t i = 0; primes.size() > i; i++){
      invprimes[primes[i]] = i+1;
    }

  }
  void generate_minfactor(){
    minp.assign(N, N+2);
    minp[0] = minp[1] = -1;
    for(int i = 2; N > i; i++){
      if(minp[i] == N+2){
        minp[i] = i;
        for(int j = i+i; N > j; j+=i){
          minp[j] = min(i, minp[j]);
        }
      }
    }
  }
  bool operator[](int x){return t[x] == x;}
};
