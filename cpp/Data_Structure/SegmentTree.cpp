//B
template< typename T,typename E >
struct SegmentTree{
  using F = function< T(T,T)>;
  int n;
  F f;
  
  vector<T> dat;
  SegmentTree(int n_,){
    init(n_);
    build
  }

  void init(int n_){
    n = 1;
    while(n < n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(int n_,vector<T> v){
    for(int i = 0; n_ > i; i++)dat[i+n-1] = v[i];
    for(int i = n-2; 0 <= i; i--)dat[i] = f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int k,E a){
    k+=n-1;
    dat[k]=
  }




}
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