#pragma once
#include "./geometry.hpp"
#include "./magnitude.hpp"

long double distance(Point a, Point b){
  return magnitude(a-b);
}
