#include "Polygon.h"

using namespace std;

int main(){
    Point point1;
    point1.x = 1.5;
    point1.y = 2;
    cout << "point 1: " << point1 << endl;

    Point point2(5.5, 2);
    cout << "point 2: " << point2 << endl;

    Polygon polygon1;
    polygon1.add(point1);
    polygon1.add(point2);
    cout << "polygon 1: " << endl << polygon1 << endl;

    polygon1.add(Point(1.5, 4.3)); 
    cout << "polygon 1: " << endl << polygon1 << endl;

    Point vector(-0.5, 1);

    Polygon polygon2 = polygon1 + vector;
    cout << "polygon 2: " << endl << polygon2 << endl;


    polygon2[0] = Point(0.3, 2.5);
    polygon2[1].x = 0.7;
    cout << "polygon 2: " << endl << polygon2 << endl;

    try {
        polygon2[3] = point1;
    } catch(IndexOutOfBoundsException e) {
        cout << "Invalid index" << endl;
    }
}