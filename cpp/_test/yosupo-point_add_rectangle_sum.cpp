#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../cpp/template/template.cpp"

#include "../../cpp/data-structure/segment-tree/2d-segment-tree.cpp"

int main(){
  int n,q;
  cin>>n>>q;

  vector<int> A;
  vector<pat> Qs;
  for(int i = 0; q > i; i++){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int r,c;
      long long v;
      scanf("%d%d%lld", &r, &c, &v);
      A.push_back(r-c);
      Qs.push_back({1,r-c,r+c,v-m});
    }else{
      int r,c;
      long long w;
      scanf("%d%d%lld", &r, &c, &w);
      Qs.push_back({2,r-c,r+c,w});
    }
  }
  sort(A.begin(),A.end());
  A.erase(unique(A.begin(),A.end()), A.end());
  map<int,int> B;
  for(int i = 0; (int)A.size() > i; i++){
    B[A[i]] = i;
  }
  vector<vector<int>> C(A.size());
  for(int i = 0; q > i; i++){
    if(Qs[i].ch == 1){
      C[B[Qs[i].r]].push_back(Qs[i].c);
    }
  }
  
  SegtreeOnSegtree st;
  st.init(C);
  
  for(int i = 0; q > i; i++){
    if(Qs[i].ch == 1){
      st.update(B[Qs[i].r], Qs[i].c, Qs[i].v);
    }else{
      long long zeroi = m;
      long long tmpx = lower_bound(A.begin(), A.end(), Qs[i].r) - A.begin();
      if(A[tmpx] == Qs[i].r){
        zeroi += st.get(tmpx, tmpx+1, Qs[i].c, Qs[i].c+1);
      }
      if(Qs[i].v <= zeroi){
        printf("0\n");
        continue;
      }

      long long mn = 0;
      long long mx = sqrt(LLONG_MAX/(m*5)); //TODO: overflow attention
      while(mx-mn > 1){
        long long ce = (mn+mx)/2;
        long long def = ((ce*2+1)*(ce*2+1)/2+1)*m;
        
        auto sx = lower_bound(A.begin(),A.end(), Qs[i].r-ce) - A.begin();
        auto tx = lower_bound(A.begin(),A.end(), Qs[i].r+ce) - A.begin();
        assert(sx <= tx);
        long long dif = st.get(sx, tx+1, Qs[i].c-ce, Qs[i].c+ce+1);
        if(def+dif < Qs[i].v){
          mn = ce;
        }else{
          mx = ce;
        }
      }
      printf("%lld\n", mx);
    }
  }
}
