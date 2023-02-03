#include "../../data-structure/union-find.cpp"

struct Kruskal {
  struct edge {
    int v1,v2,cost;
    bool operator<(const edge &p){
      return (*this).cost < p.cost;
    }
    bool operator==(const edge &p){
      return (*this).cost == p.cost;
    }
    bool operator>(const edge &p){
      return (*this).cost > p.cost;
    }
  };
  int n;
  int cost = -1;
  vector<edge> K;
  Kruskal(int n_):n(n_) {}
  void push(int v1, int v2, int cost){
    K.push_back({v1,v2,cost});
  }

  void build(){
    vector<edge> after_K;
    vector<edge> remunant_K;
    sort(K.begin(),K.end());
    UnionFind C(n);
    cost = 0;
    for(int i = 0; K.size() > i; i++){
      if(C.same(K[i].v1,K[i].v2)){
        remunant_K.push_back(K[i]);
        continue;
      }
      cost += K[i].cost;
      after_K.push_back(K[i]);
      C.unite(K[i].v1,K[i].v2);
    }
    if(after_K.size() != n-1)cost = -1;
  }
};
