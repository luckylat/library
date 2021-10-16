#include <iostream>

#include <cmath>
#include <algorithm>
#include <iomanip>

//array
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <utility>

using namespace std;



//pair<int,int>
typedef pair<int,int> P;
bool pairSecond(const P& pf,P&ps){
  return pf.second < ps.second;
}
bool pairSum(const P& pf,P&ps){
  return pf.first+pf.second > ps.first+ps.second;
}

//string
bool stringSize(const string&pf,string&ps){
  return pf.size() < ps.size();
}



