#include "../math/convolution.cpp"

struct BigInt{
  string val;
  BigInt():val("0"){}
  BigInt(string s){
    if(s == "0"){
      val = "0";
      return;
    }
    bool firstdigit = false;
    for(int i = 0; s.size() > i; i++){
      if('0' <= s[i] && s[i] <= '9'){
        if(!firstdigit && s[i] == '0')continue;
        firstdigit = true;
        val.push_back(s[i]);
      }else if(s[i] == '-' && val.empty()){
        val.push_back(s[i]);
      }else{
        val = "0";
        break;
      }
    }
  }
  BigInt(int n): val(to_string(n)){}

  BigInt abs(BigInt p) const {
    if(p.val[0] == '-'){
      p.val = p.val.substr(1,p.val.size()-1);
    }
    return p;
  }
  
  int size(){
    return (*this).val.length();
  }

  bool isZero(){
    int i = 0;
    if((*this).val[0] == '-')i = 1; 
    for(; (*this).size() > i; i++){
      if((*this).val[i] != '0')return false;
    }
    return true;
  }

  BigInt SignTurn(BigInt p) const {
    if(p.val[0] == '-'){
      p.val = p.val.substr(1,p.val.size()-1);
    }else{
      p.val = "-" + p.val;
    }
    return p;
  }
  BigInt max(BigInt a,BigInt b) const {
    if(a.val.size() > b.val.size()){
      return a;
    }else if(a.val.size() < b.val.size()){
      return b;
    }else{
      for(int i = 0; a.val.size()> i; i++){
        if(a.val[i] > b.val[i]){
          return a;
        }
        if(a.val[i] < b.val[i]){
          return b;
        }
      }
    }
    return a;
  }

  BigInt operator+(const BigInt &p) const {
    BigInt z = *this;
    BigInt k = p;
    if(z.val[0] == '-' && p.val[0] == '-'){
      return  SignTurn(abs(z)+abs(k));//(-123)+(-124) -> -((123)+(124))
    }else if(z.val[0] == '-'){
      return k-abs(z);//(-123)+(124) -> (124)-(123)
    }else if(p.val[0] == '-'){
      return (z)-abs(k);//(123)+(-124) -> (123)-(124)
    }else{
      //123 + 1234
      bool Mvup = false;
      string ret = "";
      if(z.val.size() < k.val.size()){
        swap(z,k);
      }
      //val.size() > k.val.size();
      for(int i = z.val.size()-1; 0 <= i; i--){
        if(z.val.size()-k.val.size() > i){
          //val[i]+Mvup
          ret.push_back(((z.val[i]-'0'+(Mvup?1:0))%10)+'0');
          Mvup = ((z.val[i]-'0'+(Mvup?1:0))>=10);
        }else{
          //val[i],k.val[i-(val.size()-k.val.size())]+Mvup
          ret.push_back(((z.val[i]-'0'+k.val[i-(z.val.size()-k.val.size())]-'0'+(Mvup?1:0))%10)+'0');
          Mvup = ((z.val[i]-'0'+k.val[i-(z.val.size()-k.val.size())]-'0'+(Mvup?1:0)) >= 10);
        }
      }
      if(Mvup)ret.push_back('1');
      reverse(ret.begin(),ret.end());
      if(ret.empty())ret.push_back('0');
      z.val = ret;
    }
    return z;

  }
  BigInt operator-(const BigInt &p) const {
    BigInt z = *this;
    BigInt k = p;
    if(z.val[0] == '-' && k.val[0] == '-'){
      return (z)+abs(k);//(-123)-(-123) -> (-123)+(123)
    }else if(z.val[0] == '-'){
      return (z)+SignTurn(k);//(-123)-(123) -> (-123)+(-123)
    }else if(k.val[0] == '-'){
      return abs(k)+(z);//(123)-(-123) -> (123)+(123)
    }else{
      string ret = "";
      //z >= k
      bool Mvdwn = false;
      bool minus = false;
      if(max((z),k) != z){
        minus = true;
        swap(z,k);
      }
      for(int i = z.val.size()-1; 0 <= i; i--){
        if(z.val.size() - k.val.size() > i){
          if(z.val[i]-'0' < (Mvdwn?1:0)){
            ret.push_back(10+z.val[i]-(Mvdwn?1:0));
            Mvdwn = true;
          }else{
            ret.push_back(z.val[i]-(Mvdwn?1:0));
            Mvdwn = false;
          }
        }else{
          if(z.val[i] < k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)){
            ret.push_back(10+z.val[i]-(k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)) + '0');
            Mvdwn = true;
          }else{
            ret.push_back(z.val[i]- (k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)) + '0');
            Mvdwn = false;
          }
        }
      }
      while(ret[ret.size()-1] == '0' && ret.size() > 1)ret.pop_back();
      if(minus)ret.push_back('-');
      if(ret.empty())ret.push_back('0');
      reverse(ret.begin(),ret.end());
      z.val = ret;
    }
    return z;
  }
  BigInt operator*(const BigInt &p) const {
    BigInt z = *this;
    BigInt k = p;
    bool minus = false;
    if((z.val[0] == '-') + (p.val[0] == '-') == 1)minus = true;
    string Z = abs(z).val;
    string K = abs(k).val;

    vector<mint> Zz(Z.size());
    for(int i = 0; Z.size() > i; i++){
      Zz[i] = Z[Z.size()-i-1]-'0';
    }
    vector<mint> Kk(K.size());
    for(int i = 0; K.size() > i; i++){
      Kk[i] = K[K.size()-i-1]-'0';
    }

    auto Cc = convolution(Zz, Kk);
    vector<int> C(Cc.size());
    for(int i = 0; Cc.size() > i; i++){
      C[i] = Cc[i].n;
    }
    for(int i = 0; C.size() > i; i++){
      if(C[i] >= 10 && i+1 == C.size()){
        C.push_back(C[i]/10);
      }else if(C[i] >= 10){
        C[i+1] += C[i]/10;
      }
      C[i] = C[i]%10;
    }
    C.push_back(0);
    while(C.size() != 1 && C[C.size()-1] == 0)C.pop_back();
    bool isZero = (C.size() == 1 && C[0] == 0);
    string val;
    if(minus && !isZero)val.push_back('-');
    for(int i = 0; C.size() > i; i++){
      val.push_back(C[C.size()-i-1]+'0');
    }
    BigInt ans = (BigInt)val;
    return ans;
  }

  //Only N
  BigInt operator/(const BigInt &p) const {
    BigInt z = *this;
    BigInt k = p;
    assert(k != (BigInt)"0");
    bool minus = false;
    if((z.val[0] == '-') + (p.val[0] == '-') == 1)minus = true;
    string Z = abs(z).val;
    string K = abs(k).val;
    BigInt rem = (BigInt)"0";
    BigInt ans = (BigInt)"0";
    // z / k
    for(int i = 0; Z.size() > i; i++){
      rem = rem*(BigInt)"10" + (BigInt)(Z[i]-'0');
      int nw = 0;
      while(rem >= K){
        nw++;
        rem -= K;
      }
      ans = ans*(BigInt)"10" + (BigInt)(nw);
    }
    if(minus && !ans.isZero())ans = SignTurn(ans);
    return ans;
  }
  
  BigInt operator%(const BigInt &p) const {
    BigInt z = *this;
    BigInt k = p;
    assert(k != (BigInt)"0");
    bool minus = false;
    if((z.val[0] == '-') + (p.val[0] == '-') == 1)minus = true;
    string Z = abs(z).val;
    string K = abs(k).val;
    BigInt rem = (BigInt)"0";
    BigInt ans = (BigInt)"0";
    // z / k
    for(int i = 0; Z.size() > i; i++){
      rem = rem*(BigInt)"10" + (BigInt)(Z[i]-'0');
      int nw = 0;
      while(rem >= K){
        nw++;
        rem -= K;
      }
      ans = ans*(BigInt)"10" + (BigInt)(nw);
    }
    return rem;
  }

  BigInt operator+=(const BigInt &p){return *this = (*this) + p;}
  BigInt operator-=(const BigInt &p){return *this = (*this) - p;}
  BigInt operator*=(const BigInt &p){return *this = (*this) * p;}
  BigInt operator/=(const BigInt &p){return *this = (*this) / p;}
  BigInt operator%=(const BigInt &p){return *this = (*this) % p;}

  bool operator==(const BigInt &p)const{return val == p.val;}
  bool operator!=(const BigInt &p)const{return val != p.val;}
  bool operator<(const BigInt &p)const{return val != max(*this, p).val;}
  bool operator<=(const BigInt &p)const{return (*this) == p || (*this) < p;}
  bool operator>(const BigInt &p)const{return p.val != max(*this, p).val;}
  bool operator>=(const BigInt &p)const{return (*this) == p || (*this) > p;}
  

  friend ostream &operator<<(ostream &os, const BigInt &p){
    return os << p.val;
  }
  friend istream &operator>>(istream &is, BigInt &p){
    string s;
    cin>>s;
    p = BigInt(s);
    return (is);
  }
};

