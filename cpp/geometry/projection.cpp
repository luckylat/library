#pragma once
#include "./line.hpp"
#include "./point.hpp"
#include "./vec.hpp"

long double projectionDistance(Line l, Point p){
  Line nl = standardize(l);
  return distance(l, p);
}

Point projection(Line l, Point p){
  long double dist = projectionDistance(l, p);
  Vec v = normal(l);
  return p+(v*dist);
}
