template< typename T, typename F>
struct LazySegmentTree{
  private:
    int n;
    vector<T> node,lazy;
    vector<bool> lazyTrigger;

    F f;
    T initer;

  public:
    LazySegmentTree(int n_, F f, T initer) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
      lazy.resize(2*n-1, 0);
      lazyTrigger.resize(2*n-1, false);
    }

    LazySegmentTree(int n_, F f, T initer, vector<T> base) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
      set(base);
      lazy.resize(2*n-1, 0);
      lazyTrigger.resize(2*n-1, false);
    }

    void set(vector<T> base){
      int x = 1;
      while(x < n)x *= 2;
      x--;
      for(int i = 0; base.size() > i; i++){
        node[i+x] = base[i];
      }
      for(int i = x-1; 0 <= i; i--){
        node[i] = f(node[i*2+1], node[i*2+2]);
      }
    }

    void eval(int k, int l, int r){
      if(lazyTrigger[k]){
        node[k] += lazy[k]/(r-l+1);
        if(r-l >= 1){
          lazy[k*2+1] += lazy[k]/2;
          lazyTrigger[k*2+1] = true;
          lazy[k*2+2] += lazy[k]/2;
          lazyTrigger[k*2+2] = true;

        }
        lazy[k] = 0;
        lazyTrigger[k] = false;
      }
    }

    //TODO: update -> apply(such as update and add)
    void add(int a,int b, T x, int k = 0, int l = 0, int r = -1){
      if(r < 0) r = n-1;
      eval(k, l, r);
      if(b < l || r < a){
        return;
      }
      if(a <= l && r <= b){
        lazy[k] = x*((r-l+1));
        lazyTrigger[k] = true;
        eval(k, l, r);
      }else{
        add(a,b,x,2*k+1, l, (l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2+1,r);

        node[k] = f(node[k*2+1],node[k*2+2]);
      }
    }

    T getf(int a,int b, int k=0, int l=0, int r=-1){
      if(r < 0){
        r = n-1;
      }
      if(r < a || b < l){
        return initer;
      }
      eval(k,l,r);
      if(a <= l && r <= b){
        return node[k];
      }
      T vl = getf(a,b,2*k+1,l,(l+r)/2);
      T vr = getf(a,b,2*k+2,(l+r)/2+1,r);
      return f(vl,vr);
    }

    void debug(){
      int nw = 1;
      int curr = 1;
      cout << "---begin---" << endl;
      for(int i = 0; 2*n-1 > i; i++){
        cout << "(" << node[i] << ", " << lazy[i] << " (" << lazyTrigger[i] << ")) ";
        if(nw == curr)cout << endl,nw *= 2, curr=1;
        else curr++;
      }
      cout << "---end---" << endl;
    }
};


template <typename T, typename F>
LazySegmentTree<T, F> get_lazy_segment_tree(int N, const F &f, T initer){
  return LazySegmentTree{N,f,initer};
}

template <typename T, typename F>
LazySegmentTree<T, F> get_lazy_segment_tree(int N, const F &f, T initer, vector<T> base){
  return LazySegmentTree(N, f, initer, base);
}

