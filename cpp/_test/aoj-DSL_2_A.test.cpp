#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/segment-tree/segment-tree.cpp"

int main(){
  int n,q;cin>>n>>q;
  auto B = get_segment_tree(n,[](long long a,long long b){return min(a,b);}, 2147483647LL);
  for(int i = 0; q > i; i++){
    int p;cin>>p;
    int x,y;cin>>x>>y;
    if(p == 0){
      B.update(x,y);
    }else{
      cout << B.getf(x,y) << endl;
    }
  }
}
