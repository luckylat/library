//yukicoder@cpp17
//coder:luckYrat(twitter:@luckYrat_)
//dijkstraから逃げるな
//おすすめの曲 無機質世界に彩を-MisomyL
//https://www.youtube.com/watch?v=8G590EiLQ3E

//標準入出力
#include <iostream>

#include <cmath>
#include <algorithm>

#include <iomanip>

//コンテナ系
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

#include <bitset>

//複素数
#include <complex>

#include <cctype>
#include <utility>
#include <climits>


#include <numeric>

//なまえくーかん！
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

//てーすう！
const int mod = 1000000007;
const int inf = (1<<30)-1;
const ll linf = (1LL<<62LL)-1;
const double EPS = (1e-10);

//でふぁいん！
#define anyfill(n,s) setw(n) << setfill(s)
#define loop(s) for(int i = 0; s > i; i++)
#define rep(i,q) for(int i = 0; (q) > i; i++)
#define repp(i,n,q) for(int i = n; (q) > i; i++)
#define dep(i,q) for(int i = (q); 0 < i; i--)

//みじかく！
#define pb push_back
#define mkp make_pair
#define fir first
#define scn second
#define ednl endl

//いぇすのー！
#define YesNo(a) (a?"Yes":"No")
#define YESNO(a) (a?"YES":"NO")
#define yesno(a) (a?"yes":"no")

//きんぼーnほーこー！！
P ar4[4] = {mkp(0,1),mkp(0,-1),mkp(1,0),mkp(-1,0)};
P ar8[8] = {mkp(-1,-1),mkp(-1,0),mkp(-1,1),mkp(0,-1),mkp(0,1),mkp(1,-1),mkp(1,0),mkp(1,1)};
P x[3] = {{1,2},{2,3},{3,5}};
/*
確認ポイント
cout << fixed << setprecision(n) << 小数計算//n桁の小数表記になる

計算量は変わらないが楽できるシリーズ
min(max)_element(iter,iter)で一番小さい(大きい)値のポインタが帰ってくる
count(iter,iter,int)でintがiterからiterの間にいくつあったかを取得できる
*/
__attribute__((constructor))
void initial() {
 cin.tie(0);
 ios::sync_with_stdio(false);
}