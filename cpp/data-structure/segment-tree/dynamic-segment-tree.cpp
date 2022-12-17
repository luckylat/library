
template< typename T >
struct Node{
  T v;
  Node* left, right

  Node(): left(nullptr),right(nullptr) {}
}


template< typename T, typename F>
struct SegmentTree{
  private:
    int n;
    Node node;

    F f;
    T initer;

  public:
    SegmentTree(int n_, F f, T initer) : f(f),initer(initer) {
      n = 1;
      while(n < n_)n*=2;
    }

    void update(int x, T val){
    }

    void add(int x, T val){
    }

    T getf(int a,int b, int k=0, int l=0, int r=-1){
    }

};

template <typename T, typename F>
SegmentTree<T, F> get_segment_tree(int N, const F &f, T initer){
  return SegmentTree<T,F>{N,f,initer};
}

