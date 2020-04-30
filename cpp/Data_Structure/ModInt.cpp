#include <iostream>
using namespace std;
const int mod = 1000000007;
//B
template <int mod>
struct ModInt{
  int n;
  ModInt():n(0){}
  ModInt(int n_):n(n_ >= 0 ? n_%mod : mod - ((-n_)%mod) ){}

  ModInt &operator+=(const ModInt &p){
    if((n+=p.n) >= mod)n-=mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p){
    n+=mod-p.n;
    if(n >= mod)n-=mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p){
    n = (int) ((1LL*n*p.n)%mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p){
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const {return ModInt(-n);}
  ModInt operator+(const ModInt &p) const {return ModInt(*this) += p;}
  ModInt operator-(const ModInt &p) const {return ModInt(*this) -= p;}
  ModInt operator*(const ModInt &p) const {return ModInt(*this) *= p;}
  ModInt operator/(const ModInt &p) const {return ModInt(*this) /= p;}

  bool operator==(const ModInt &p) const {return n==p.n;}
	bool operator<(const ModInt &p) const {return n<p.n;}
	bool operator>(const ModInt &p) const {return n>p.n;}
	bool operator>=(const ModInt &p) const {return n>=p.n;}
	bool operator<=(const ModInt &p) const {return n<=p.n;}
  bool operator!=(const ModInt &p) const {return n!=p.n;}

  ModInt inverse() const {
    int a = n,b = mod,u = 1,v = 0;
    while(b){
      int t = a/b;
      a -= t*b; swap(a,b);
      u -= t*v; swap(u,v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t z) const {
    ModInt ret(1),mul(n);
    while(z > 0){
      if(z & 1) ret *= mul;
      mul *= mul;
      z >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p){
    return os << p.n;
  }
  friend istream &operator>>(istream &is, ModInt &a){
    int64_t t;
    is >> t;
    a = ModInt<mod> (t);
    return (is);

  }
};
using mint = ModInt<mod>;
//E
int main(){//https://atcoder.jp/contests/abc156/submissions/10514541
  int n,a,b;cin>>n>>a>>b;
  mint z = 2;
  z = z.pow(n)-1;
  mint tmp = 1;
  for(int i = 1; a >= i; i++){
    tmp *= (n-a+i);
    tmp /= i;
  }
  z -= tmp;
  tmp = 1;
  for(int i = 1; b >= i; i++){
    tmp *= (n-b+i);
    tmp /= i;
  }
  cout << z-tmp << endl;
  
}