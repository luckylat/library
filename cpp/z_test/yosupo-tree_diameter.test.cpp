#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../cpp/template/template.cpp"

#include "../../cpp/graph/tree/tree-diameter.cpp"



int main(){
  int n;cin>>n;
  TreeDiameter<long long> A(n);
  for(int i = 0; n-1 > i; i++){
    int a,b,c;cin>>a>>b>>c;
    A.add(a,b,c);
  }
  long long ret = A.build();
  cout << ret << " " << A.path.size() << endl;
  for(int i = 0; A.path.size() > i; i++){
    cout << A.path[i] << " \n"[i+1==A.path.size()];
  }
}
