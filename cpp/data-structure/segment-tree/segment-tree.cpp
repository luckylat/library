template< typename T, typename F>
struct SegmentTree{
  private:
    int n;
    vector<T> node;

    F f;
    T initer;

  public:
    SegmentTree(int n_, F f, T initer) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
    }

    SegmentTree(int n_, F f,T initer, vector<T> x) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
      set(x);
    }

    void set(vector<T> x){
      for(int i = 0; (int)x.size() > i; i++){
        update(i,x[i]);
      }
    }

    void update(int x, T val){
      x += (n-1);

      node[x] = val;

      while(x > 0){
        x = (x-1)/2;
        node[x] = f(node[2*x+1],node[2*x+2]);
      }
    }

    void add(int x, T val){
      x += (n-1);
      
      node[x] += val;
      while(x > 0){
        x = (x-1)/2;
        node[x] = f(node[2*x+1],node[2*x+2]);
      }
    }

    T getf(int a,int b, int k=0, int l=0, int r=-1){
      
      if(r < 0){
        r = n-1;
      }
      if(r < a || b < l){
        return initer;
      }
      if(a <= l && r <= b){
        return node[k];
      }

      T vl = getf(a,b,2*k+1,l,(l+r)/2);
      T vr = getf(a,b,2*k+2,(l+r)/2+1,r);
      return f(vl,vr);
    }

};

template <typename T, typename F>
SegmentTree<T, F> get_segment_tree(int N, const F &f, T initer){
  return SegmentTree<T,F>{N,f,initer};
}

template <typename T, typename F>
SegmentTree<T, F> get_segment_tree(int N, const F &f, T initer, vector<T> x){
  return SegmentTree<T,F>{N,f,initer,x};
}
