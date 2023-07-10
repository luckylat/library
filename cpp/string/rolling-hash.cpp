struct charSet{
  int base = 52;
  int encode(char c){
    if('0' <= c && c <= '9'){
      return c-'0';
    }else if('A' <= c && c <= 'Z'){
      return c-'A'+10;
    }else if('a' <= c && c <= 'z'){
      return c-'a'+10+26;
    }
    return -1;
  }
};

struct RollingHash{
  charSet C;
  string t;
  const long long MOD1 = 1000000007;
  const long long MOD2 = 998244353;
  vector<int> stringIdx[1000001];
  map<pair<long long, long long>, int> hashIdx;
  int idxSize;

  RollingHash(string s, int n){
    idxSize = 0;
    long long val1 = 0;
    long long val2 = 0;
    long long baseMOD1 = 1;
    long long baseMOD2 = 1;
    for(int i = 0; n > i; i++){
      baseMOD1 = (baseMOD1*C.base)%MOD1;
      baseMOD2 = (baseMOD2*C.base)%MOD2;
      val1 = (val1*C.base + C.encode(s[i]))%MOD1;
      val2 = (val2*C.base + C.encode(s[i]))%MOD2;
    }
    for(int i = n; s.size() >= i; i++){
      if(!hashIdx[make_pair(val1, val2)]){
        hashIdx[make_pair(val1, val2)] = hashIdx.size();
      }
      stringIdx[hashIdx[make_pair(val1, val2)]].push_back(i-n);
      if(i!=s.size()){
        val1 = ((val1*C.base + C.encode(s[i]))%MOD1 - (baseMOD1 * C.encode(s[i-n]))%MOD1 + MOD1)%MOD1;
        val2 = ((val2*C.base + C.encode(s[i]))%MOD2 - (baseMOD2 * C.encode(s[i-n]))%MOD2 + MOD2)%MOD2;
      }
    }
    idxSize = hashIdx.size();
  }

  RollingHash(string s, string x): RollingHash(s, (int)x.size()){
    t = x;
  }

  //len(x) should be n
  pair<long long, long long> hash(string x){
    long long val1 = 0;
    long long val2 = 0;
    for(int i = 0; x.size() > i; i++){
      val1 = (val1*C.base + C.encode(x[i]))%MOD1;
      val2 = (val2*C.base + C.encode(x[i]))%MOD2;
    }
    return make_pair(val1, val2);
  }

  vector<int> search(){
    return search(t);
  }

  vector<int> search(string x){
    auto hashedString = hash(x);
    return stringIdx[hashIdx[hashedString]];
  }

  int distMax(){
    int distMx = 0;
    for(int i = 1; idxSize >= i; i++){
      distMx = max(distMx, stringIdx[i][stringIdx[i].size()-1]-stringIdx[i][0]);
    }
    return distMx;
  }
};

