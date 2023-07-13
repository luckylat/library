#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../template/template.cpp"

#include "../string/rolling-hash.cpp"

int main(){
  string s;cin>>s;
  string t;cin>>t;
  RollingHash r(s, t);
  auto x = r.search();
  for(int i = 0; x.size() > i; i++){
    cout << x[i] << endl;
  }
}
