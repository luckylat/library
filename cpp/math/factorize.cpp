//B
template<typename T>
pair<int,map<T,int>> Factorize(T n){
  map<T,int> a;
  int b = 0;
  
  for(T i = 2; n >= i*i; i++){
    while(!(n%i)){
      n/=i;
      a[i]++;
      b++;
    }
  }
  if(n != 1)a[n]++,b++;
  return make_pair(b,a);
}
//E
