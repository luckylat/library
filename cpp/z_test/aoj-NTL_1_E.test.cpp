#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../cpp/template/template.cpp"

#include "../../cpp/math/expansion-gcd.cpp"

int main(){
  int a,b;cin>>a>>b;
  int x,y;
  auto A = extgcd(a,b);
  cout << A.first << " " << A.second << endl;
}

