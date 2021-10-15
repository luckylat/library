#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../Cpp/_Template/Template.cpp"

#include "../../Cpp/Data_Structure/UnionFind.cpp"



int main(){
  int N,Q;cin>>N>>Q;
  UnionFind A(N);
  for(int i = 0; Q > i; i++){
    int t,u,v;cin>>t>>u>>v;
    if(t){
      cout << (A.same(u,v)?1:0) << endl;
    }else{
      A.unite(u,v);
    }
  }
}