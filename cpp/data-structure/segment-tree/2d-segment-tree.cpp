struct Segtree{
  int N;
  vector<long long> val;
  void init(int n){
    N = 1;
    while(N < n) N *= 2;
    val = vector<long long>(N*2, 0); 
  }

  void update(int i, long long v){
    i += N;
    val[i] += v;
    while(i > 1){
      i /= 2;
      val[i] = val[i*2] + val[i*2+1];
    }
  }

  long long get(int x, int y, int k, int l, int r){
    if(r <= x || y <= l)return 0;
    if(x <= l && r <= y)return val[k];

    auto a = get(x, y, k*2, l, (l+r)/2);
    auto b = get(x, y, k*2+1, (l+r)/2, r);
    return a+b;
  }
  long long get(int x, int y){
    return get(x, y, 1, 0, N);
  }
};

struct SegtreeOnSegtree{
  int N;
  vector<Segtree> st;
  vector<vector<int>> index;

  void init(vector<vector<int>> &v){
    int n = v.size();
    N = 1;
    while(N < n) N *= 2;
    index.resize(N * 2);
    for(int i = 0; n > i; i++){
      for(int j = 0; (int)v[i].size() > j; j++){
        index[i+N].push_back(v[i][j]);
      }
    }
    for(int i = N*2-1; 1 <= i; i--){
      sort(index[i].begin(),index[i].end());
      index[i].erase(unique(index[i].begin(),index[i].end()), index[i].end());
      for(int j = 0; (int)index[i].size() > j; j++){
        index[i/2].push_back(index[i][j]);
      }
    }
    st.resize(2*N);
    for(int i = 1; 2*N > i; i++)st[i].init(index[i].size());
  }

  void update(int x,int y, long long v){//x: compressed, y: uncompressed
    assert(x < N);
    x += N;
    while(x) {
      int yy = lower_bound(index[x].begin(),index[x].end(),y) - index[x].begin();
      assert(yy != (int)index[x].size());
      assert(y == index[x][yy]);
      st[x].update(yy,v);
      x /= 2;
    }
  }

  long long get(int sx, int tx, int sy, int ty, int k, int l, int r){
    assert(k < N*2);
    assert(l < r);
    if(r <= sx || tx <= l)return 0;
    if(sx <= l && r <= tx){
      //TODO: is it correct?
      int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
      int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
      return st[k].get(syy, tyy);
    }
    int ce = (l+r)/2;
    long long le = get(sx, tx, sy, ty, k * 2, l, ce);
    long long ri = get(sx, tx, sy, ty, k * 2 + 1, ce, r);
    return le+ri;
  }

  long long get(int sx, int tx, int sy, int ty){
    return get(sx, tx, sy, ty, 1, 0, N);
  }
};
