#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 1e-8

#include "../../cpp/template/template.cpp"

#include "../../cpp/geometry/projection.cpp"

int main(){
  Point p1,p2;cin>>p1>>p2;
  Line l(p1, p2);
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    Point q;cin>>q;
    cout << fixed << setprecision(10) << projection(l,q) << endl;
  }
}
