#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/potentialized-union-find.cpp"



int main(){
  int n,q;cin>>n>>q;
  PUnionFind A(n);
  for(int i = 0; q > i; i++){
    int t;cin>>t;
    if(t){
      int x,y;cin>>x>>y;
      auto ret = A.diff(x,y);
      if(ret.first)cout << ret.second << endl;
      else cout << "?" << endl;
    }else{
      int x,y,z;cin>>x>>y>>z;
      A.unite(x,y,z);
    }
  }
}
