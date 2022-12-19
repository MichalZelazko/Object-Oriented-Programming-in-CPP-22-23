#include "Point.h"

using namespace std;

class IndexOutOfBoundsException{};

class Polygon{
    public:
        Point* vertices;
        size_t size;
        Polygon();
        Polygon(Point p);
        Polygon(const Polygon& poly);
        Polygon& operator=(const Polygon& poly);
        ~Polygon();
        Polygon& add(Point p);
        friend ostream& operator<<(ostream& os, const Polygon& poly);
        friend Polygon operator+(const Polygon& poly, const Point& p);
        Point& operator[](size_t index);
};