//
// Created by Administrator on 2020/10/25.
//

#include "Point.h"
#include <cmath>

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::distanceToOrigin() const {
    return distance(*this, Point());
}

double Point::distance(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
