#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/tree/lowest-common-ancestor.cpp"

int main(){
  int n,q;cin>>n>>q;
  vector<vector<int>> edge(n);
  for(int i = 0; n-1 > i; i++){
    int x;cin>>x;
    edge[x].push_back(i+1);
  }
  
  LCA lca(n, edge);
  for(int i = 0; q > i; i++){
    int u,v;cin>>u>>v;
    cout << lca.compute(u,v) << endl;
  }
}
