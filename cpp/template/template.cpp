//yukicoder@cpp17

#include <iostream>

#include <cmath>
#include <algorithm>

#include <iomanip>

#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

#include <bitset>

#include <complex>

#include <cctype>
#include <utility>
#include <climits>

#include <numeric>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 998244353;
const ll MODx = 1000000007;
const int INF = (1<<30)-1;
const ll LINF = (1LL<<62LL)-1;
const double EPS = (1e-10);

#define anyfill(n,s) setw(n) << setfill(s)
#define loop(s) for(int (i) = 0; (s) > (i); (i)++)
#define rep(i,q) for(int (i) = 0; (q) > (i); (i)++)
#define repp(i,n,q) for(int (i) = (n); (q) > (i); (i)++)
#define dep(i,q) for(int (i) = (q); 0 < (i); (i)--)

#define pb push_back
#define mkp make_pair
#define fir first
#define scn second

P ar4[4] = {mkp(0,1),mkp(0,-1),mkp(1,0),mkp(-1,0)};
P ar8[8] = {mkp(-1,-1),mkp(-1,0),mkp(-1,1),mkp(0,-1),mkp(0,1),mkp(1,-1),mkp(1,0),mkp(1,1)};


template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
 
 /*
確認ポイント
cout << fixed << setprecision(n) << 小数計算//n桁の小数表記になる

計算量は変わらないが楽できるシリーズ
min(max)_element(iter,iter)で一番小さい(大きい)値のポインタが帰ってくる
count(iter,iter,int)でintがiterからiterの間にいくつあったかを取得できる
*/

/*
function corner below
*/


/*
Function corner above
*/

__attribute__((constructor))
void initial() {
 cin.tie(0);
 ios::sync_with_stdio(false);
}