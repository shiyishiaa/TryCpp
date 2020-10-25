package com.norman.trycpp;

public class NativeMethods {
    /**
     * Square the double value
     *
     * @param base base
     * @return the square of the base
     */
    public static native double square(double base);

    /**
     * Return the lower case of the string.
     *
     * @param s the string to be convert
     * @return the lower case of string
     */
    public static native String toLowerCase(String s);

    /**
     * Return the area of given three points. Non-given value will be set as 0.
     *
     * @param value six point value (x1,y1,x2,y2,x3,y3,)
     * @return area
     */
    public static native double triangleArea(double... value);

    /**
     * Get the average of double array.
     *
     * @param nums numbers
     * @return average
     */
    public static native double getAverage(double... nums);

    /**
     * Calculate the distance between two points.
     *
     * @param A Point A
     * @param B Point B
     * @return distance
     */
    public static native double getDistance(Point A, Point B);
}
