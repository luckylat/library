template <typename T>
bool isPrime(T n){
  
  for(T i = 2; n >= i*i; i++){
    if(!(n%i)){return false;}
  }
  return true;
}

