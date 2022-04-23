template <typename T>
pair<T,T> extgcd(T a,T b){
  if(b!=0){
    auto A = extgcd(b,a%b);
    T tmp = A.second;
    A.second = A.first-(a/b)*A.second;
    A.first = tmp;
    return A;
  }else{
    return {1,0};
  }
}