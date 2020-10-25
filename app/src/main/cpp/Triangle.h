//
// Created by Administrator on 2020/10/25.
//

#ifndef TRYCPP_TRIANGLE_H
#define TRYCPP_TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point A, B, C;
public:
    explicit Triangle(Point A = Point(), Point B = Point(), Point C = Point());

    double perimeter();

    double area();

    static Triangle of(double *value);
};


#endif //TRYCPP_TRIANGLE_H
