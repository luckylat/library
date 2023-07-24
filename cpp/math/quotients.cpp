vector<long long> quotients(long long x){
  vector<long long> ret;
  long long nw = 1;
  while(!ret.size() || ret[ret.size()-1] != x/nw){
    if(x < nw)break;
    ret.push_back(x/nw);
    nw++;
  }
  while(ret[ret.size()-1] != 1){
    ret.push_back(ret[ret.size()-1]-1);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
