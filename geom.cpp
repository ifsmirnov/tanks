#include "geom.hpp"

#include <cmath>

Point::Point() :
    x_(0), y_(0) {  }
Point::Point(double x, double y) :
    x_(x), y_(y) {  }

double Point::x() const { return x_; }
double Point::y() const { return y_; }

Point Point::operator +(const Point& point) const { return Point(x() + point.x(), y() + point.y()); }
Point Point::operator -(const Point& point) const { return Point(x() - point.x(), y() - point.y()); }
Point Point::operator *(double factor) const { return Point(x() * factor, y() * factor); }

Point Point::operator +=(const Point& point) { x_ += point.x(); y_ += point.y(); return *this; }
Point Point::operator -=(const Point& point) { x_ -= point.x(); y_ -= point.y(); return *this; }
Point Point::operator *=(double factor) { x_ *= factor; y_ *= factor; return *this; }

double Point::angle() const { return atan2(y(), x()); }
double Point::angleTo(const Point &point) const { return (point - *this).angle(); }

double Point::length() const { return sqrt(x()*x() + y()*y()); }
double Point::distanceTo(const Point &point) const { return (point - *this).length(); }
