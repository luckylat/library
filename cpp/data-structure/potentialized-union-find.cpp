struct PotentializedUnionFind {
  int n;
  vector<int> par;
  vector<int> size_;
  vector<int> weight_val;
  PotentializedUnionFind(int n_) : n(n_), par((size_t)n_), size_((size_t)n_,1), weight_val((size_t)n_,0){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  int root(int x){
    if(par[x] == x){
      return x;
    }

    int r = root(par[x]);
    weight_val[x] += weight_val[par[x]];
    return par[x] = r;
  }

  int weight(int x){
    root(x);
    return weight_val[x];
  }

  pair<bool,int> diff(int x, int y){
    if(!same(x,y))return {false, 0};
    return {true, weight(y) - weight(x)};
  }

  void unite(int a,int b,int c){
    c += weight(a);
    c -= weight(b);
    int ra = root(a);
    int rb = root(b);
    if(size_[ra] < size_[rb]){
      swap(ra, rb);
      swap(a,b);
      c = -c;
    }
    if(ra==rb){
      return;
    }

    par[rb] = ra;
    size_[ra] += size_[rb];
    weight_val[rb] = c;
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
using PUnionFind = PotentializedUnionFind;
