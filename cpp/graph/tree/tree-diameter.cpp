template<typename T>
struct TreeDiameter{
  int n;
  vector<vector<int>> tree; 
  TreeDiameter(int n_) : n(n_),tree(n_) {

  }

  void add(int s,int v){
    tree[s].emplace_back(v);
    tree[v].emplace_back(s);
  }

  int build(){
    auto x = DFS(0);
    auto y = DFS(x.first);
    return y.second;
  }



private:
  vector<int> lck;
  pair<int,int> DFS(int nw,int dist=0,int initnal=1){
    if(initnal == 1){
      lck.assign(n,false);
      initnal = 0;
    }
    lck[nw] = 1;
    pair<int,int> ret = make_pair(nw,dist);
    for(int i = 0; tree[nw].size() > i; i++){
      if(!lck[tree[nw][i]]){
        pair<int,int> x = DFS(tree[nw][i],dist+1,initnal);
        if(ret.second < x.second){
          ret = x;
        }
      }
    }
    return ret;
  }
};