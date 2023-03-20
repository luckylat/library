#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/segment-tree/segment-tree.cpp"

int main(){
  int n,q;cin>>n>>q;
  vector<long long> A(n);
  for(int i = 0; n > i; i++){
    cin>>A[i];
  }
  
  auto B = get_segment_tree(n,[](long long a,long long b){return a+b;},0LL, A);
  for(int i = 0; q > i; i++){
    int p;cin>>p;
    int x,y;cin>>x>>y;
    if(p == 0){
      B.add(x,y);
    }else{
      cout << B.getf(x,y-1) << endl;
    }
  }
}
