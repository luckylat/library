using namespace std;
//B
template <typename T>
T uPow(T z,T n, T mod){
  T ans = 1;
  while(n != 0){
    if(n%2){
      ans*=z;
      if(mod)ans%=mod;
    }
    n >>= 1;
    z*=z;
    if(mod)z%=mod;
  }
  return ans;
}
//E

int main(){//https://atcoder.jp/contests/atc002/submissions/9878231
  long long n,m,p;cin>>n>>m>>p;
  cout << uPow(n,p,m) << endl;
}