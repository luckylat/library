#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/shortest-path/dijkstra.cpp"



int main(){
  int n,m,s,t;cin>>n>>m>>s>>t;
  dijkstra<long long> A(n);
  for(int i = 0; m > i; i++){
    int a,b,c;cin>>a>>b>>c;
    A.push(a,b,c);
  }
  A.build(s);
  if(A[t] == INF)cout << -1 << endl;
  else{
    auto R = A.restoration(t);
    cout << A[t] << " " << R.size() << endl;
    for(int i = 0; R.size() > i; i++){
      cout << R[i].first << " " << R[i].second << endl;
    }
  }
}
