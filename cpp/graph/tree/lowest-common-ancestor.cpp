#include "../../data-structure/segment-tree/segment-tree.cpp"

struct EulerTourForLCA {
  int n;
  vector<vector<int>> edge;
  vector<pair<int, int>> timeline;
  vector<pair<int,int>> stump;
  vector<int> parent;
  EulerTourForLCA(int n, vector<vector<int>> edge):
    n(n), edge(edge), timeline(2*n, {-1, 0}), stump(n, {-1,-1}), parent(n, 0), lock(n, false) {}

  void build(int top){
    timer = 0;
    lock.assign(n, false);
    lock[top] = true;
    dfs(top, 0);
  }
  const pair<int,int> operator[](int index){
    return stump[index];
  }
private:
  vector<bool> lock;
  int timer = 0;
  void dfs(int vertex, int depth){
    stump[vertex].first = timer;
    timeline[timer].first = vertex;
    timeline[timer].second = depth;
    timer++;
    for(int i = 0; (int)edge[vertex].size() > i; i++){
      if(!lock[edge[vertex][i]]){
        lock[edge[vertex][i]] = true;
        parent[edge[vertex][i]] = vertex;
        dfs(edge[vertex][i], depth+1);
      }
    }
    stump[vertex].second = timer;
    timeline[timer].first = parent[vertex];
    timeline[timer].second = depth-1;
    timer++;
  }
};


struct LowestCommonAncestor {
  int n;
  vector<vector<int>> edge;
  EulerTourForLCA et;
  function<pair<int,int>(pair<int,int>, pair<int,int>)> RMQ = [](pair<int,int> a, pair<int,int> b){
    if(a.second < b.second)return a;
    return b;
  };
  //function<const pair<int,int>> RMQ = [](pair<int,int> a, pair<int,int> b){
  //};
  SegmentTree<pair<int,int>, decltype(RMQ)> st;

  LowestCommonAncestor(int n, vector<vector<int>> edge):n(n), edge(edge), et(n, edge), st(2*n, RMQ, {n+1, n+1}){
    et.build(0);
    st.set(et.timeline);
  }

  int compute(int l, int r){
    auto ls = et[l].first;
    auto rs = et[r].first;
    if(ls > rs)swap(ls, rs);
    auto mn = st.getf(ls, rs);
    return mn.first;
  }
};
using LCA = LowestCommonAncestor;

