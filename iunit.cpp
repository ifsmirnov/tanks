#include "iunit.hpp"

#include <cmath>

IUnit::IUnit(const model::Unit &unit) :
    unit_(unit) {  }

long long IUnit::id() const { return unit_.id(); }
double IUnit::width() const { return unit_.width(); }
double IUnit::height() const { return unit_.height(); }
double IUnit::x() const { return unit_.x(); }
double IUnit::y() const { return unit_.y(); }
Point IUnit::pos() const { return Point(x(), y()); }
double IUnit::speedX() const { return unit_.speed_x(); }
double IUnit::speedY() const { return unit_.speed_y(); }
Point IUnit::speed() const { return Point(speedX(),speedY()); }
double IUnit::angle() const { return unit_.angle(); }
double IUnit::angularSpeed() const { return unit_.angular_speed(); }

double IUnit::angleTo(const IUnit &unit) const { return pos().angleTo(unit.pos()); }
double IUnit::angleTo(const model::Unit &unit) const { return unit_.GetAngleTo(unit); }
double IUnit::angleTo(double x, double y) const { return unit_.GetAngleTo(x, y); }
double IUnit::distanceTo(const IUnit &unit) const {return pos().distanceTo(unit.pos()); }
double IUnit::distanceTo(const Point &point) const { return pos().distanceTo(point); }
double IUnit::distanceTo(const model::Unit &unit) const { return unit_.GetDistanceTo(unit); }
double IUnit::distanceTo(double x, double y) const { return unit_.GetDistanceTo(x, y); }

Point IUnit::getVertex(int vertexId) const
{
    /*
       3--0
       |  |
       2--1
    */
    const static double mf = 0.42; // marginFactor
    const static double xMultiplier[4] = {mf, -mf, -mf, mf};
    const static double yMultiplier[4] = {mf, mf, -mf, -mf};

    Point offset(width() * xMultiplier[vertexId] - 3, height() * yMultiplier[vertexId] - 3);
    offset = offset.turned(sin(angle()), cos(angle()));

    return pos() + offset;
}

double IUnit::whenWillBeHitBy(Point start, Point dir) const
{
    double res = 1e10;
    for (int i = 0; i < 4; i++)
    {
        Point p1 = getVertex(i),
              p2 = getVertex((i+1)%4);
        double t = geom::timeToReachSegment(start, dir, p1, p2);
        if (t > -0.5 && t < res)
        {
            //std::cerr << "relax with " << i << "  " << p1 << "  " << p2 << std::endl;
            res = t;
        }
    }
    return res > 1e9 ? -1 : res;
}
double IUnit::whenWillBeHitByWithOffset(Point start, Point dir) const
{
    double expectedTime = start.distanceTo(pos()) / dir.length();
    Point expectedWay = speed() * expectedTime;
    start -= expectedWay;
    double res = 1e10;
    for (int i = 0; i < 4; i++)
    {
        Point p1 = getVertex(i),
              p2 = getVertex((i+1)%4);
        double t = geom::timeToReachSegment(start, dir, p1, p2);
        if (t > -0.5 && t < res)
        {
            //std::cerr << "relax with " << i << "  " << p1 << "  " << p2 << std::endl;
            res = t;
        }
    }
    return res > 1e9 ? -1 : res;
}
