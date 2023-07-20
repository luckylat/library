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

    void eval(int k, int l, int r){
      if(lazyTrigger[k]){
        node[k] = lazy[k];
        if(r-l >= 1){
          lazy[k*2+1] = lazy[k];
          lazyTrigger[k*2+1] = true;
          lazy[k*2+2] = lazy[k];
          lazyTrigger[k*2+2] = true;

        }
        lazy[k] = 0;
        lazyTrigger[k] = false;
      }
    }

    //TODO: update -> apply(such as update and add)
    void update(int a,int b, T x, int k = 0, int l = 0, int r = -1){
      if(r < 0) r = n-1;
      eval(k, l, r);
      if(b < l || r < a){
        return;
      }
      if(a <= l && r <= b){
        lazy[k] = x;
        lazyTrigger[k] = true;
        eval(k, l, r);
      }else{
        update(a,b,x,2*k+1, l, (l+r)/2);
        update(a,b,x,2*k+2,(l+r)/2+1,r);

        node[k] = f(node[k*2+1],node[k*2+2]);
      }
    }

    T getf(int a,int b, int k=0, int l=0, int r=-1){
      if(r < 0){
        r = n-1;
      }
      if(r < a || b < l)return initer;
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
