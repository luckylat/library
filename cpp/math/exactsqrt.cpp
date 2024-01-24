// 整数型を取得することを想定
template <typename T>
T CeilExactSqrt(int c, T x){
  T mn = 0;
  T mx = x;
  while(mx-mn > 1){
    T ce = (mn+mx)/2;
    T nw = 1;
    for(int i = 0; c > i; i++){
      if(x/ce < nw){
        mx = ce;
        break;
      }
      nw *= ce;
      if(i+1 == c && x == nw){
        mx = ce;
      }
    }
    if(mx != ce)mn = ce;
  }
  return mx;
}

template <typename T>
T FloorExactSqrt(int c, T x){
  T mn = 0;
  T mx = x;
  while(mx-mn > 1){
    T ce = (mn+mx)/2;
    T nw = 1;
    for(int i = 0; c > i; i++){
      if(x/ce < nw){
        mx = ce;
        break;
      }
      nw *= ce;
    }
    if(mx != ce)mn = ce;
  }
  return mn;
}
