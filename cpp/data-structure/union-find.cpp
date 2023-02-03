struct UnionFind {
  int n;
  vector<int> par;
  vector<int> size_;
  UnionFind(int n_) : n(n_), par((size_t)n_), size_((size_t)n_,1){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  int root(int x){
    if(par[x] == x)return x;
    return par[x] = root(par[x]);
  }

  void unite(int a,int b){
    int ra = root(a);
    int rb = root(b);
    if(ra==rb)return;
    if(size(ra) > size(rb)) swap(ra,rb);
    par[ra] = rb;
    size_[rb] += size_[ra];
  }

  bool same(int a, int b){
    return root(a) == root(b);
  }

  int size(int a){
    return size_[root(a)];
  }
  void debug(){
    for(int i = 0; n > i; i++){
      cout << size_[root(i)] << " ";
    }
    cout << endl;

    return;
  }
};
