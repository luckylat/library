#pragma once
#include "./vec.hpp"
#include "./point.hpp"
#include "./line-segment.hpp"

struct LineVec{
  Point base;
  Vec vec;
  LineVec(LineSegment ls){
    base = ls.first;
    vec = ls.second - ls.first;
  }
};
