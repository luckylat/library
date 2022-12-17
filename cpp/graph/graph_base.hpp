#pragma once

template<typename T = int>
struct edge{
  int from,to;
  T cost;
};

template<typename T = int>
struct graph{
  vector< vector<edge<T>>> g;

  //Undirected-Path
  void add_edge(int from, int to, T cost = T(1)){
    g[from].emplace_back(from,to,cost);
    g[to].emplace_back(to,from,cost);
  }

  //Directed-Path
  void add_directed_edge(int from,int to, T cost = T(1)){
    g[from].emplace_back(from,to,cost);
  }

  //read
  void read(int M, int index = 1, bool directed = false, bool weighted = false){
    for(int i = 0; M > i; i++){
      int a,b;cin>>a>>b;
      a-=index;b-=index;
      T c = T(1);
      if(weighted)cin>>c;


      if(directed) add_directed_edge(a,b,c);
      else add_edge(a,b,c);

    }
  }

  inline const vector<vector<edge<T>>> &operator[](const int &k){
    return g[k];
  }


};