#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-deprecated-headers"
//
// Created by Administrator on 2020/10/25.
//

#include "Triangle.h"
#include <math.h>

Triangle::Triangle(Point A, Point B, Point C) {
    this->A = A;
    this->B = B;
    this->C = C;
}

double Triangle::area() {
    double a = Point::distance(B, C);
    double b = Point::distance(C, A);
    double c = Point::distance(A, B);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() {
    return Point::distance(A, B) + Point::distance(B, C) + Point::distance(C, A);
}

Triangle Triangle::of(double *value) {
    double xy[6];
    for (double &i : xy) {
        i = value == nullptr ? 0 : *value;
        value++;
    }
    return Triangle(Point(xy[0], xy[1]), Point(xy[2], xy[3]), Point(xy[4], xy[5]));
}

#pragma clang diagnostic pop