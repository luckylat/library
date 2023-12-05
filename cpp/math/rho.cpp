#include "./miller-rabin.cpp"

using namespace std;
template <typename T>
struct Rho{
	mt19937 mt; //32 bit version
	T N;
  vector<T> factor;
  //std::mt19937_64 mt(rnd()); //64 bit version
  Rho(T n):N(n){
	  random_device rnd;
    mt.seed(rnd());
  }


  vector<T> run(){
    factor = factors(N);
    sort(factor.begin(), factor.end());
    return factor;
  }

private:
  __int128 c;
  T f(__int128 x, T n){
    return (x*x + c)%n;
  }

  T find_factor(T n){
    c = mt()%n;
    T base = mt()%n;
    T d = 1;
    T x = base;
    T y = base;
    while(true){
      x = f(x, n);
      y = f(f(y,n),n);
      d = __gcd(abs(x-y), n);
      if(d == n){
        return -1;
      }else if(d != 1){
        return d;
      }
    }
  }

  vector<T> factors(T n){
    if(n == 1)return {};
    if(n == 4)return {2, 2};
    if(MillerRabinCheck(n)){
      return {n};
    }

    T factor = -1;
    while(factor == -1){
      factor = find_factor(n);
    }

    vector<T> f1 = factors(factor);
    vector<T> f2 = factors(n/factor);
    f1.insert(f1.end(), f2.begin(), f2.end());

    return f1;
  }
};
