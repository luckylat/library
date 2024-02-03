// Ref: https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda

#include "./binary-power-method.cpp"
#include "../data-structure/mod-int/mod-int.cpp"
using namespace std;

template<typename MINT>
vector<MINT> ntt(vector<MINT> X, int depth, vector<MINT> root) {
  long long n = X.size();
  if(n == 1){
    return X;
  }else{
    vector<MINT> val(0);
    vector<MINT> even(0);
    vector<MINT> odd(0);
    for(int i = 0; n > i; i++){
      if(i % 2 == 0)even.push_back(X[i]);
      else odd.push_back(X[i]);
    }

    auto ntt_even = ntt(even, depth-1, root);
    auto ntt_odd = ntt(odd, depth-1, root);

    mint r = root[depth];

    MINT now = 1;
    for(int i = 0; n > i; i++){
      val.push_back(ntt_even[i%(n/2)] + (now * ntt_odd[i%(n/2)]));
      now *= r;
    }
    return val;
  }
}

template<typename MINT> // 998244353 mod
vector<MINT> make_root(long long p){
  vector<MINT> val(0);
  mint r = uPow(3LL, 119LL, p);
  for(int i = 0; 23 > i; i++){
    val.push_back(r);
    r *= r;
  }
  reverse(val.begin(), val.end());
  return val;
}

template<typename MINT>
vector<MINT> make_invroot(vector<MINT> root){
  vector<MINT> val(0);
  for(int i = 0; 23 > i; i++){
    val.push_back(root[i].inverse());
  }
  return val;
}

template<typename MINT>
vector<MINT> convolution(vector<MINT> A, vector<MINT> B){
  long long p = A[0].getMod(); // each mod must be same

  vector<MINT> root = make_root<MINT>(p);
  vector<MINT> invroot = make_invroot<MINT>(root);

  size_t size = (A.size()+B.size()-1);
  int n = 1;
  int log2_n = 0;
  while(n < size){
    n *= 2;
    log2_n++;
  }
  
  while(A.size() < n)A.push_back(0);
  while(B.size() < n)B.push_back(0);

  // AとBのNTTを求める
  auto nttA = ntt(A, log2_n-1, root);
  auto nttB = ntt(B, log2_n-1, root);

  vector<MINT> nttC(n);
  for(int i = 0; n > i; i++){
    nttC[i] = nttA[i]*nttB[i];
  }

  auto nC = ntt(nttC, log2_n-1, invroot);
  vector<MINT> C(size);
  for(int i = 0; size > i; i++){
    C[i] = nC[i]/(mint)n;
  }

  return C;
}

