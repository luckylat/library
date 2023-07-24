#define PROBLEM "https://yukicoder.me/problems/no/117"

#include "../template/template.cpp"
#include "../math/combination.cpp"

int main(){
  Combination C(2000010, MODx);
  int q;cin>>q;
  char _;
  for(int i = 0; q > i; i++){
    char c;cin>>c>>_;
    int a,b;cin>>a>>_>>b>>_;
    if(c == 'C')cout << C.C(a,b) << endl;
    else if(c == 'P')cout << C.P(a,b) << endl;
    else cout << C.H(a,b) << endl;
  }
}
