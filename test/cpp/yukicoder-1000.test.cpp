#define PROBLEM "https://yukicoder.me/problems/no/1000"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/union-find.cpp"

int main(){//https://yukicoder.me/submissions/440699
  int n,q;cin>>n>>q;
  vector<long long> A(n);
  vector<long long> B(n);
  for(int i = 0; n > i; i++){
    cin>>A[i];
    B[i] = 0;
  }
  lazyBIT<long long> Z(n);
  for(int i = 0; q > i; i++){
    char c;long long x,y;cin>>c>>x>>y;
    if(c == 'A'){
      //bit[x]+=y;
      if(Z.query(x,x)){
        int m = Z.query(x,x);
        B[x-1] += m*A[x-1];
        Z.add(x,m*-1);
      }
      A[x-1] += y;
    }else{
      Z.rangeadd(x,y,1);
    }
  }
  for(int j = 0; n > j; j++){
    cout << B[j]+Z.query(j+1,j+1)*A[j];
    if(j+1 != n)cout << " ";
  }
  cout << endl;
}