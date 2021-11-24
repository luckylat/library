struct UnionFind {
  vector<int> par;
  vector<int> size_;
  int n;
  UnionFind(int n) : n(n), par((size_t)n), size_((size_t)n,1){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  int root(int n){
    if(par[n] == n)return n;
    return par[n] = root(par[n]);
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



