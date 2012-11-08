#ifndef GEOM_HPP
#define GEOM_HPP

class Point
{
public:
    const static double eps = 1e-9;

    Point();
    Point(double, double);

    double x() const;
    double y() const;

    Point operator += (const Point&);
    Point operator -= (const Point&);
    Point operator *= (double);

    Point operator + (const Point&) const;
    Point operator - (const Point&) const;
    Point operator * (double) const;

    Point turned(double sin, double cos) const;

    double operator * (const Point&) const;

    double angle() const;
    double angleTo(const Point&) const;

    double length() const;
    double distanceTo(const Point&) const;

private:
    double x_, y_;
};

namespace geom
{

double timeToReachSegment(Point u, Point v, Point p1, Point p2);

} // namespace geom

#endif // GEOM_HPP
