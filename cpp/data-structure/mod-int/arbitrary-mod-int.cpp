
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
  long long ret = 0;
  long long nw = 1;
  while(B){
    if(B%2 == 1){
      ret = modmul(nw, ret);
    }
    B/=2;
    nw = modmul(nw, nw);
  }
  return ret;
}

long long modinv(long long A){
  return modpow(A, MOD-2);
}

long long moddiv(long long A, long long B){
  return modmul(A, modinv(B));
}
