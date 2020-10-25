//
// Created by Administrator on 2020/10/25.
//

#ifndef TRYCPP_POINT_H
#define TRYCPP_POINT_H

class Point {
private:
    double x, y;

public:
    explicit Point(double x = 0, double y = 0);

    double distanceToOrigin() const;

    static double distance(Point A, Point B);
};

#endif //TRYCPP_POINT_H
