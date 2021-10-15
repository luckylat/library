#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//B
template<typename T>
struct BIT{//1_Indexed
  int n;
  vector<T> bit;
  BIT(int n_):n(n_+1),bit(n,0){}

  T sum(int a){
  int ret = 0;
  for(int i = a; i > 0; i -= i & -i) ret += bit[i];
  return ret;
  }

  void add(int a,int w){
    for(int i = a; i <= n; i += i & -i)bit[i] += w;
  }

  T query(int l,int r){
    return sum(l-1)-sum(r-1);
  }

};
//E