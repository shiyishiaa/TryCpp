package com.norman.trycpp;

public class Point {
    private double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static double getDistance(Point A, Point B) {
        return Math.sqrt(Math.pow(A.x - B.x, 2) + Math.pow(A.y - B.y, 2));
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }
}
