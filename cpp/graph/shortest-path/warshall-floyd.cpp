class FloydWarshall {
  long long MAX;
  void run(){
    for(int k = 0; n > k; k++){
      for(int i = 0; n > i; i++){
        for(int j = 0; n > j; j++){
          if(dist[i][k] == MAX || dist[k][j] == MAX)continue;
          dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
      }
    }
  }
public:
  int n;
  vector<vector<long long>> dist;//MAX以上なら辺はなし
  FloydWarshall(int n_,long long MAX = 2e18+1):n(n_),MAX(MAX),dist(n_,vector<long long>(n_,MAX)){
    for(int i = 0; n > i; i++){
      dist[i][i] = 0;
    }
  }

  //双方向
  void push(int s,int v,long long c){
    dist[s][v] = min(dist[s][v],c);
    dist[v][s] = min(dist[s][v],c);
  }
  void update(int s,int v,long long c){
    dist[s][v] = c;
    dist[v][s] = c;
  }

  void push_p(int s,int v,long long c){
    dist[s][v] = min(dist[s][v],c);
  }
  void update_p(int s,int v,long long c){
    dist[s][v] = c;
  }
  
  bool negative(){
    for(int i = 0; n > i; i++){
      if(dist[i][i] < 0)return true;
    }
    return false;
  }

  bool isInf(int s,int v){
    return dist[s][v] == MAX;
  }

  void build(){
    run();
  }

};
