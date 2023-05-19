#pragma once

#include "point.hpp"

struct LineSegment{
  Point first, second;
  LineSegment(Point a, Point b):first(a),second(b){}
};


