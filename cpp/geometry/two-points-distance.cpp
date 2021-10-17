double two_point_distance(double x1,double y1,double x2,double y2){
  double x_distrance = abs(x2-x1);
  double y_distrance = abs(y2-y1);
  return sqrt(y_distrance*y_distrance+x_distrance*x_distrance);
}
