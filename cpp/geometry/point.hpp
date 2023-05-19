#pragma once
#include "./vec.hpp"

struct Point{
  long double x,y;

  Vec operator-(Point b){
    return {x-b.x, y-b.y};
  }
  Point operator+(long double a){
    return {x+a, y+a};
  }
  Point operator+(Vec v){
    return {x+v.x, y+v.y};
  }

  friend istream &operator>>(istream &is, Point &p){
    long double a,b;
    cin>>a>>b;
    p = Point({a,b});
    return (is);
  }

  friend ostream &operator<<(ostream &os, const Point &p){
    return os << p.x << " " << p.y;
  }

};
