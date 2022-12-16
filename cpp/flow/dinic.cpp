struct dinic{
    const long long INF = 1000000000;
    const int n;
    struct edge {
        int to, cap, rev;
    };
    vector<edge> G
    vector<int> rank;
    dinic(int n_):n(n_),G(n_),rank(n_),first(n_*(n_+1)/2{}
    
    void push(int n,int m,int cap){
        int n_index = G[n].size();
        int m_index = G[m].size();
        G[n].push_back(m,cap,m_index);
        G[m].push_back(n,cap,n_index);
    }
    
    void bfs(int x){
        struct ranks{
            int v,d;
        };
        queue<ranks> K;
        for(int i = 0; n > i; i++){
            rank[i] = -1;
        }
        K.push(x,1);
        while(K.size()){
            auto z = K.front();K.pop();
            rank[z.v] = z.d;
            for(int i = 0; G[z.v].size() > i; i++){
                if(G[z.v][i].cap)K.push(G[z.v][i].to,z.d+1);
            }
        }
    }

    long long dfs(int s, int t, int lev, long long mx=INF){
        if(s==t)return mx;
        for(int i = 0; G[s].size() > i; i++){
            if(rank[G[s][i]].to == lev+1){
                mx = min(mx,dfs(G[s][i].to,t,lev+1,min(mx,G[s][i].cap)));
            }
        }
        return mx;
    }

    long long run(int s,int t){
        long long ret = 0;
        while(true){
            bfs(s);
            if(rank[t] == -1)break;
            auto x = dfs(s,t,1);
            if(x > 0){
                ret += x;

        }
        return ret;

    }
}

