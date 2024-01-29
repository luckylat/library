#pragma once

template <int mod>
struct ModInt{
  int n;
  ModInt():n(0){}
  ModInt(long long n_):n(n_ >= 0 ? n_%mod : mod - ((-n_)%mod) ){}
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

  int getMod() const {
    return mod;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p){
    return os << p.n;
  }
  friend istream &operator>>(istream &is, ModInt &a){
    int64_t t;
    is >> t;
    a = ModInt<mod> ((long long)t);
    return (is);

  }
};
using mint = ModInt<MOD>;
