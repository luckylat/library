#include <iostream>
#include <vector>
using namespace std;

//B
struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  int root(int n){
    if(par[n] == n)return n;
    return par[n] = root(par[n]);
  }

  void unite(int a,int b){
    int ra = root(a);
    int rb = root(b);
    if(ra==rb)return;
    par[ra] = rb;
  }

  bool same(int a, int b){
    return root(a) == root(b);
  }
};
//E

int main(){//https://judge.yosupo.jp/submission/1859
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

