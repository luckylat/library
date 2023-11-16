template <typename T>
struct mat{
  vector<vector<T>> x;
  int h,w;
  mat():x(vector<vector<T>>()){}
  mat(int h,int w):x(vector<vector<T>>(h,vector<T>(w))),h(h),w(w){}
  mat(int h,int w, T c):x(vector<vector<T>>(h,vector<T>(w,c))),h(h),w(w){}
  mat(vector<vector<T>> A):x(A),h(A.size()),w(A[0].size()){}
  vector<T>& operator[](int i){return x[i];}

  void resize(int h, int w){
    x.assign(h, vector<T>(w, 0));
  }

  mat base(){
    return mat(h,w,0);
  }

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


  // Requirement: h==w
  pair<bool, mat> inv(){
    if(h != w)return {false, base()};
    mat<T> gaussianMat(h, 2*w, 0);
    for(int i = 0; h > i; i++){
      for(int j = 0; w > j; j++){
        gaussianMat[i][j] = (*this)[i][j];
      }
    }
    for(int i = 0; h > i; i++){
      gaussianMat[i][w+i] = 1;
    }

    for(int i = 0; h > i; i++){
      for(int j = i; h > j; j++){
        if(gaussianMat[j][i] != 0){
          swap(gaussianMat[i], gaussianMat[j]);
        }
      }
      T initCoeffient = gaussianMat[i][i];
      if(initCoeffient == 0){
        return {false, base()};
      }
      for(int j = 0; 2*w > j; j++){
        gaussianMat[i][j] /= initCoeffient;
      }
      for(int j = i+1; h > j; j++){
        T deleteCoeffient = gaussianMat[j][i] * -1;
        for(int k = i; 2*w > k; k++){
          gaussianMat[j][k] += deleteCoeffient * gaussianMat[i][k];
        }
      }
    }

    for(int i = 0; h > i; i++){
      if(gaussianMat[i][i] != 1){
        T normarizeCoeffient = gaussianMat[i][i];
        if(normarizeCoeffient == 0)continue;
        for(int j = i; 2*w > j; j++){
          gaussianMat[i][j] /= normarizeCoeffient;
        }
      }
    }

    for(int i = h-1; 0 <= i; i--){
      for(int j = 0; i > j; j++){
        T deleteCoeffient = gaussianMat[j][i] * -1;
        for(int k = i; 2*w > k; k++){
          gaussianMat[j][k] += deleteCoeffient * gaussianMat[i][k];
        }
      }
    }

    mat v(h, w);
    for(int i = 0; h > i; i++){
      for(int j = 0; w > j; j++){
        v[i][j] = gaussianMat[i][j+w];
      }
    }
    return {true, v};
  }

  friend istream &operator>>(istream &is, mat &m){
    for(int i = 0; m.h > i; i++){
      for(int j = 0; m.w > j; j++){
        is>>m.x[i][j];
      }
    }
    return is;
  }

  friend ostream &operator<<(ostream &os, const mat &m){
    for(int i = 0; m.h > i; i++){
      for(int j = 0; m.w > j; j++){
        os << m.x[i][j];
        if(j+1 != m.w)cout << " ";
      }
      if(i+1 != m.h)cout << "\n";
    }
    return os;
  }
};
