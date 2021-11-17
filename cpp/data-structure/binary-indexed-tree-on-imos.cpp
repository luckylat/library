//********
//これ嘘なので本当に気にしないでください
//********

template<typename T>
struct lazyBIT{//1_Indexed
  int n;
  vector<T> bit;
  vector<T> range;
  lazyBIT(int n_):n(n_+1),bit(n,0),range(n,0){}

  T sum(int a){
    T ret = 0;
    for(int i = a; i > 0; i -= i & -i) ret += bit[i];
    return ret;
  }
  T rangesum(int a){
    T ret = 0;
    for(int i = a; i > 0; i -= i & -i) ret += range[i];
    return ret;
  }

  void add(int a,T w){
    for(int i = a; i <= n; i += i & -i)bit[i] += w;
  }
  void rangeadd(int x,int y,T w){// x < y
    y++;
    for(int i = x; i <= n; i += i & -i)range[i] += w;
    for(int i = y; i <= n; i += i & -i)range[i] -= w;
  }

  T query(int l,int r){
    if(r==1){
      return sum(l)+rangesum(l);
    }
    return sum(l)-sum(r-1)+rangesum(l);
  }


};
