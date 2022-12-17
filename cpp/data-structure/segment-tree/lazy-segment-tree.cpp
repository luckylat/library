template< typename T, typename F>
struct LazySegmentTree{
  private:
    int n;
    vector<T> node,lazy;

    F f;
    T initer;

  public:
    SegmentTree(int n_, F f, T initer) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
      lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r){
      if(lazy[k] != 0){
        node[k] += lazy[k];

        if(r-l > 1){
          node[k*2+1] += lazy[k]/2;
          node[k*2+2] += lazy[k]/2;
        }
        lazy[k] = 0;
      }
    }

    void add(int a,int b, T x, int k = 0, int l = 0, int r = -1){
      if(r < 0) r = n;
      eval(k, l, r);
      if(b <= l || r <= a){
        return;
      }
      if(l <= a && b <= r){
        lazy[k] += (r-l)*x;
        eval(k, l, r);
      }else{
        add(a,b,2*k+1, l, (l+r)/2);
        add(a,b,2*k+2,(l+r)/2+1,r);

        node[k] = f(node[k*2+1],node[k*2+2]);
      }
    }

    T getf(int a,int b, int k=0, int l=0, int r=-1){
      if(r < 0){
        r = n;
      }
      if(r <= a || b <= l)return initer;
      eval(k,l,r);
      if(a <= l && r <= b)return node[k];
      T vl = getf(a,b,2*k+1,l,(l+r)/2);
      T vr = getf(a,b,2*k+2,(l+r)/2+1,r);
      return f(vl,vr);
    }
};

template <typename T, typename F>
LazySegmentTree<T, F> get_segment_tree(int N, const F &f, T initer){
  return SegmentTree{N,f,initer};
}
