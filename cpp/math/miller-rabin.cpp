#include "binary-power-method.cpp"
/*
true: 素数
false: 合成数
*/
template<typename T>
bool MillerRabinCheck(T n){
  if(n == 1)return false;
  if(n%2 == 0){
    return n == 2;
  }
  __int128 d = n-1;
  __int128 s = 0;
  while(d%2 == 0){
    d/=2;
    s++;
  }
  vector<__int128> base = {2,3,5,7,11,13,17,19,23,29,31,37};
  for(int i = 0; base.size() > i; i++){
    if(base[i] >= n)break;
    long long current = (long long)uPow(base[i],d,(__int128)n);
    if(current == 1 || current == n-1)continue;
    bool ok = false;
    for(int j = 0; s > j; j++){
      current = ((__int128)current * (__int128)current) % n;
      if(current == n-1){
        ok = true;
        break;
      }
    }
    if(!ok)return false;
  }
  return true;
}
