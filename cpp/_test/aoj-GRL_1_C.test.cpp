#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/shortest-path/warshall-floyd.cpp"

int main(){
  int v,e;cin>>v>>e;
  FloydWarshall A(v);
  for(int i = 0; e > i; i++){
    int x,y,c;cin>>x>>y>>c;
    A.push_p(x,y,c);
  }
  A.build();
  if(A.negative()){
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for(int i = 0; v > i; i++){
    for(int j = 0; v > j; j++){
      if(A.isInf(i,j)){
        cout << "INF";
      }else{
        cout << A.dist[i][j];
      }
      if(j+1 != v)cout << " ";
    }
    cout << endl;
  }
}