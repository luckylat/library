#pragma once

long long modadd(long long A, long long B){
  return (A+B)%MOD;
}

long long modsub(long long A, long long B){
  return ((A-B)%MOD+MOD)%MOD;
}

long long modmul(long long A, long long B){
  return (A*B)%MOD;
}

long long modpow(long long A, long long B){
  long long ret = 1;
  long long mul = A;
  while(B){
    if(B%2 == 1){
      ret = modmul(mul, ret);
    }
    B/=2;
    mul = modmul(mul, mul);
  }
  return ret;
}

long long modinv(long long A){
  return modpow(A, MOD-2);
}

long long moddiv(long long A, long long B){
  return modmul(A, modinv(B));
}
