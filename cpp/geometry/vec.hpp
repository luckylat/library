#pragma once

struct Vec{
  long double x,y;
  Vec operator*(long double a){
    return {x*a, y*a};
  }
  Vec operator/(long double a){
    return {x/a, y/a};
  }

  friend ostream &operator<<(ostream &os, const Vec &p){
    return os << p.x << " " << p.y;
  }
};

long double magnitude(Vec v){
  return sqrt(v.x*v.x+v.y*v.y);
}

Vec standardize(Vec v){
  return v/magnitude(v);
}
