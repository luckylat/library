#pragma once

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

