template<typename T>
struct ValueUnionFind {
  int n;
  vector<int> par;
  vector<T> cost;
  int size;
  
  //Todo: Costに対する二項演算も取れるようにする
  ValueUnionFind(int n) : n(n),par((size_t)n,-1), cost((size_t)n), size(n){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  //結合関連
  int root(int n){
    if(par[n] == n)return n;
    return par[n] = root(par[n]);
  }

  void unite(int a,int b){
    int ra = root(a);
    int rb = root(b);
    if(ra==rb)return;
    size--;
    par[ra] = rb;
    cost[rb] += cost[ra];
  }

  bool same(int a, int b){
    return root(a) == root(b);
  }

  //コスト関連
  void build(T x){
    for(int i = 0; n > i; i++){
      cost[i] = x;
    }
  }

  void add(T x, int n){
    cost[root(n)]+=x;
  }

  void update(T x, int n){
    cost[root(n)] = x;
  }

  //出力関連
  int groupSize(){
    return size;
  }

  T operator[](int i){
    return cost[root(i)];
  }
};
template<class T>
using VUnionFind = ValueUnionFind<T>;
