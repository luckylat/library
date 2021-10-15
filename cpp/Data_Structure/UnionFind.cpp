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



