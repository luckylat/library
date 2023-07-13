#define PROBLEM "https://yukicoder.me/problems/no/1344"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/shortest-path/warshall-floyd.cpp"


int main(){
  int n,m;cin>>n>>m;
  FloydWarshall A(n);
  for(int i = 0; m > i; i++){
    long long a,b,c;cin>>a>>b>>c;
    A.push_p(--a,--b,c);
  }
  A.build();
  for(int i = 0; n > i; i++){
    long long ans = 0;
    for(int j = 0; n > j; j++){
      if(i==j || A.isInf(i,j))continue;
      ans += A.dist[i][j];
    }
    cout << ans << endl;
  }
}
