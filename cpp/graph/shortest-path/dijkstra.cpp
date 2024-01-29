template<typename T>
class dijkstra{
  struct vg{
    int t;
    T c;
  };
  vector<pair<int,T>> cost;
  int beg = -1;
  void run(int x){
    auto comp = [](vg a,vg b){
      return a.c>b.c;
    };
    priority_queue<vg,vector<vg>,decltype(comp)> R{comp};
    for(int i = 0; n > i; i++){
      cost[i].second = -1;
    }
    cost[x].first = -1;
    cost[x].second = 0;
    R.push({x,0});
    while(R.size()){
      auto k = R.top();R.pop();
      if(cost[k.t].second != k.c)continue;
      for(int i = 0; A[k.t].size() > i; i++){
        if(cost[A[k.t][i].t].second != -1 && cost[A[k.t][i].t].second <= k.c+A[k.t][i].c)continue;
        cost[A[k.t][i].t].second = k.c+A[k.t][i].c;
        cost[A[k.t][i].t].first = k.t;
        R.push({A[k.t][i].t,k.c+A[k.t][i].c});
      }
    }

  }

public:
  int n;
  vector<vector<vg>> A;
  vector<vector<vg>> Rev;
  dijkstra(int n_):n(n_),A(n_),Rev(n_),cost(n_,{-1,-1}){}

  //双方向
  void push(int s,int v,T c){
    A[s].push_back({v,c});
    A[v].push_back({s,c});
    Rev[s].push_back({v,c});
    Rev[v].push_back({s,c});
  }

  void push_side(int s,int v,T c){
    A[s].push_back({v,c});
    Rev[v].push_back({s,c});
  }

  void build(int x){
    run(x);
    beg = x;
  }

  //restorate any

  vector<int> restoration(int t = -1){
    vector<int> Ret;
    if(beg == -1 || (t != -1 && cost[t].second == -1)){
      Ret.push_back(-1);
      return Ret;
    }
    int ind = t;
    if(ind == -1){
      T tmp = cost[0].second;
      int tmpin = 0;
      for(int i = 0; n > i; i++){
        if(tmp < cost[i].second){
          tmp = cost[i].second;
          tmpin = i;
        }
      }
      ind = tmpin;
    }
    Ret.push_back(ind);
    while(beg != ind){
      Ret.push_back({cost[ind].first});
      ind = cost[ind].first;
    }
    reverse(Ret.begin(),Ret.end());
    return Ret;
  }

  T operator[](int i){
    return cost[i].second;
  }
};
