template<typename T>
class dijkstra{
  struct vg{
    int t;
    T c;
  };
  vector<T> cost;
  void run(int x){
    auto comp = [](vg a,vg b){
      return a.c>b.c;
    };
    priority_queue<vg,vector<vg>,decltype(comp)> R{comp};
    for(int i = 0; n > i; i++){
      cost[i] = -1;
    }
    cost[x] = 0;
    R.push({x,0});
    while(R.size()){
      auto k = R.top();R.pop();
      if(cost[k.t] != k.c)continue;
      for(int i = 0; A[k.t].size() > i; i++){
        if(cost[A[k.t][i].t] != -1 && cost[A[k.t][i].t] <= k.c+A[k.t][i].c)continue;
        cost[A[k.t][i].t] = k.c+A[k.t][i].c;
        R.push({A[k.t][i].t,k.c+A[k.t][i].c});
      }
    }

  }

public:
  int n;
  vector<vector<vg>> A;
	dijkstra(int n_):n(n_),A(n_),cost(n_,-1){}

  //双方向
  void push(int s,int v,int c){
    A[s].push_back({v,c});
    A[v].push_back({s,c});
  }

  void push_side(int s,int v,int c){
    A[s].push_back({v,c});
  }

  void build(int x){
    run(x);
  }

  vector<pair<int,int>> restoration(int t){
    vector<pair<int,int>> Ret
  }

  int operator[](int i){
    return cost[i];
  }
  
};
