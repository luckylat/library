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

  T query(int r,int l){
    return sum(l-1)-sum(r-1);
  }


  int lower_bound(T x){
    if(x <= 0){
      return 0;
    }
    x--;
    int t = 1;
    while(t < n)t <<= 1;
    int st = 0;
    int base = 0;
    for(; t; t/=2){
      if(st+t <= n && base+bit[st+t] <= x){
        base += bit[st+t];
        st += t;
      }
    }
    return st+1;
  }
};
