template<typename T>
struct TreeDiameter{
  struct edge{
    int to;
    T cost;
  };
  int n;
  T generated;
  vector<vector<edge>> tree; 
  vector<int> path;
  vector<int> C;
  
  TreeDiameter(int n_) : n(n_),tree(n_) {
    generated = -1;
  }

  void add(int s,int v){
    tree[s].push_back({v,1});
    tree[v].push_back({s,1});
    generated = -1;
  }

  void add(int s,int v,T c){
    tree[s].push_back({v,c});
    tree[v].push_back({s,c});
    generated = -1;
  }

  T build(){
    if(generated != -1)return generated;
    auto x = DFS(0);
    auto y = DFS(x.first);
    int nw = x.first;
    while(y.first != nw){
      path.push_back(nw);
      nw = C[nw];
    }
    path.push_back(nw);
    return generated = y.second;
  }

private:
  //DFS(int, T, (int)) -> pair<int,int>
  pair<int,T> DFS(int nw,T dist=0,int initnal=1){
    if(initnal){
      C.assign(n,-1);
      path.clear();
      initnal = 0;
    }
    C[nw] = 0;
    pair<int,T> ret = make_pair(nw,dist);
    for(int i = 0; tree[nw].size() > i; i++){
      if(C[tree[nw][i].to] == -1){
        pair<int,T> x = DFS(tree[nw][i].to,dist+tree[nw][i].cost,0);
        if(ret.second < x.second){
          ret = x;
          C[nw] = tree[nw][i].to;
        }
      }
    }
    return ret;
  }
};
