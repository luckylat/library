#pragma once
#include "./line.hpp"
#include "./point.hpp"
#include "./vec.hpp"
#include "./projection.cpp"

Point reflection(Line l, Point p){
  long double dist = projectionDistance(l, p);
  Vec v = normal(l);
  return p+(v*(dist*2));
}
