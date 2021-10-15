//B
template< typename T>
struct SegmentTree{
  private:
    int n;
    vector<T> node;

  public:
    SegmentTree(int n_, T initer){
      n = 1;
      while(n < n_)n*=2;
      node.resize(2*n-1, initer);
    }

    void update(int x, T val){
      x += (n-1);

      node[x] = val;

      while(x > 0){
        x = (x-1)/2;
        node[x] = max(node[2*x+1],node[2*x+2]);
      }
    }

    int getmax(int a,int b, int k=0, int l=0, int r=-1){
      if(r < 0) r = n;
      if(r <= a || b <= l)return 0;
      if(a <= l && r <= b)return node[k];

      T vl = getmax(a,b,2*k+1,l,(l+r)/2);
      T vr = getmax(a,b,2*k+2,(l*r)/2,r);
      return max(vl,vr);
    }
};
//E

int main(){
  int N,Q;cin>>N>>Q;
  SegmentTree<
  for(int i = 0; N > i; i++){
    int c,x,y;cin>>c>>x>>y;
    if(c){
      //query
    }else{
      //update
    }
  }
}