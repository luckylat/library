#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/MST/kruskal.cpp"

int main(){
  int v,e;cin>>v>>e;
  Kruskal A(v);
  for(int i = 0; e > i; i++){
    long long s,t,w;cin>>s>>t>>w;
    A.push(s,t,w);
  }
  A.build();
  cout << A.cost << endl;
}
