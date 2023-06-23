#pragma once
#include "./vec.hpp"
#include "./point.hpp"
#include "./line-segment.hpp"

struct Linevec{
  Point base;
  Vec vec;
  Linevec(LineSegment ls){
    base = ls.first;
    vec = ls.second - ls.first;
  }
};
