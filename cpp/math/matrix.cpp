template <typename T>
struct mat{
  vector<vector<T>> x;
  int h,w;
  mat():x(vector<vector<T>>()){}
  mat(int h,int w):x(vector<vector<T>>(h,vector<T>(w))),h(h),w(w){}
  mat(int h,int w, T c):x(vector<vector<T>>(h,vector<T>(w,c))),h(h),w(w){}
  mat(vector<vector<T>> A):x(A),h(A.size()),w(A[0].size()){}
  vector<T>& operator[](int i){return x[i];}
  

  mat& operator*=(mat& y){
    mat<T> ret(h,y.w,0);
    if(w != y.h){
      for(int i = 0; h > i; i++){
        for(int j = 0; y.w > j; j++){
          ret[i][j] = -1;
        }
      }
    }else{
      for(int i = 0; h > i; i++){
        for(int j = 0; y.w > j; j++){
          for(int k = 0; w > k; k++){
            ret[i][j] = ret[i][j] + x[i][k]*y[k][j];
          }
        }
      }
    }
    for(int i = 0; h > i; i++){
      x[i].resize(y.w);
    }
    w = y.w;
    for(int i = 0; h > i; i++){
      for(int j = 0; y.w > j; j++){
        x[i][j] = ret[i][j];
      }
    }
    return *this;
  }

  mat operator*(mat& y){return mat(*this) *= y;}


  mat pow(long long n){//正方行列のみ
    mat<T> res(h,w);
    mat<T> ret(h,w,0);
    mat<T> a(h,w);
    for(int i = 0; h > i; i++){
      ret[i][i] = 1;
    }
    for(int i = 0; h > i; i++){
      for(int j = 0; w > j; j++){
        a[i][j] = (*this)[i][j];
      }
    }
    while(n > 0){
      if(n & 1){
        ret *= a;
      }
      a *= a;
      n/=2;
    }
    for(int i = 0; h > i; i++){
      for(int j = 0; w > j; j++){
        res[i][j] = ret[i][j];
      }
    }
    return res;
  }
};
