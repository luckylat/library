//S
struct SieveEratos{
  vector<bool> t;
  SieveEratos(int n):t(n+1,true){
    t[0] = t[1] = false;
    for(int i = 2; n >= i; i++){
      if(t[i]){
        for(int j = i+i; n >= j; j+=i){
          t[j] = false;
        }
      }
    }
  }
  bool operator[](int x){return t[x];}
};
//E

