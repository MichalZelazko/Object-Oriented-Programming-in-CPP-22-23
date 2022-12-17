#include "Polygon.h"

Polygon::Polygon(){
    this->vertices = NULL;
    this->size = 0;
}

Polygon::Polygon(Point p){
    this->vertices = NULL;
    this->vertices = (Point*)realloc(this->vertices, sizeof(Point));
    // this->vertices = new Point[1];
    this->vertices[0] = p;
    this->size = 1;
}

Polygon::Polygon(const Polygon& poly){
    this->vertices = NULL;
    this->vertices = (Point*)realloc(this->vertices, poly.size * sizeof(Point));
    for(size_t i = 0; i < poly.size; i++){
        this->vertices[i] = poly.vertices[i];
    }
    this->size = poly.size;
    // Point* aux = new Point[poly.size];
    // for(size_t i = 0; i < this->size; i++){
    //     aux[i] = this->vertices[i];
    // }
    // delete[] this->vertices;
    // this->vertices = aux;
    // this->size = poly.size;
}

Polygon::~Polygon(){
    // delete[] this->vertices;
    free(this->vertices);
}

Polygon& Polygon::operator=(const Polygon& poly){
    this->vertices = (Point*)realloc(this->vertices, poly.size * sizeof(Point));
    for(size_t i = 0; i < poly.size; i++){
        this->vertices[i] = poly.vertices[i];
    }
    this->size = poly.size;
    // Point* aux = new Point[poly.size];
    // for(size_t i = 0; i < this->size; i++){
    //     aux[i] = this->vertices[i];
    // }
    // delete[] this->vertices;
    // this->vertices = aux;
    // this->size = poly.size;
    return * this;
}

Polygon& Polygon::add(Point p){
    this->vertices = (Point*)realloc(this->vertices, (this->size + 1) * sizeof(Point));
    this->vertices[this->size] = p;
    this->size++;
    // Point* aux = new Point[this->size + 1];
    // size_t i = 0;
    // for(i = 0; i < this->size; i++){
    //     aux[i] = this->vertices[i];
    // }
    // aux[i] = p;
    // delete[] this->vertices;
    // this->vertices = aux;
    // this->size++;
    return *this;
}

ostream& operator<<(ostream& os, const Polygon& poly){
    for(size_t i = 0; i < poly.size; i++){
        os << "point " << i << ": " << poly.vertices[i] << endl;
    }
    return os;
}

Polygon operator+(const Polygon& poly, const Point& p){
    Polygon result(poly);
    for(size_t i = 0; i < poly.size; i++){
        result.vertices[i].x += p.x;
        result.vertices[i].y += p.y;
    }
    return result;
}

Point& Polygon::operator[](size_t index){
    if(index > this->size - 1){
        throw IndexOutOfBoundsException();
    }
    return this->vertices[index];
}