#pragma once
#include "linevec.hpp"
#include "point.hpp"
#include "vec.hpp"

struct Line{
  //ax+by+c=0 (required: a*a+b*b != 0)
  long double a,b,c;
  Line(long double a, long double b, long double c): a(a), b(b), c(c){}
  Line(LineVec lv){
    a = -lv.vec.y;
    b = lv.vec.x;
    c = -(a*lv.base.x + b*lv.base.y);
  }

  Line operator/(long double v){
    return {a/v, b/v, c/v};
  }

  Line(LineSegment ls){
    (*this) = (LineVec)(ls);
  }
  Line(Point a, Point b){
    LineSegment ls({a,b});
    (*this) = (LineSegment)(ls);
  }
};

Line standardize(Line l){
  return l/sqrt(l.a*l.a+l.b*l.b);
}
long double distance(Line l, Point p){
  Line nl = standardize(l);
  return nl.a*p.x + nl.b*p.y + nl.c;
}
Vec normal(Line l){
  Vec v = {-l.a, -l.b};
  return standardize(v);
}

