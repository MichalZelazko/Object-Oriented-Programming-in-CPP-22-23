#pragma once
#include <iostream>

using namespace std;

class Point{
    public:
        double x;
        double y;
        Point(double x = 0, double y = 0);
        Point(const Point& p);
        Point& operator=(const Point& p);
        ~Point();
        friend ostream& operator<<(ostream& os, const Point& p);
};