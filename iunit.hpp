#ifndef IUNIT_HPP
#define IUNIT_HPP

#include "model/Unit.h"
#include "geom.hpp"

class IUnit
{
public:
    IUnit(const model::Unit &unit);

    long long id() const;
    double width() const;
    double height() const;
    double x() const;
    double y() const;
    Point pos() const;
    double speedX() const;
    double speedY() const;
    Point speed() const;
    double angle() const;
    double angularSpeed() const;

    double angleTo(double x, double y) const;
    double angleTo(const model::Unit& unit) const;
    double angleTo(const IUnit& unit) const;
    double distanceTo(double x, double y) const;
    double distanceTo(const Point &point) const;
    double distanceTo(const model::Unit& unit) const;
    double distanceTo(const IUnit& unit) const;

    Point getVertex(int vertexId) const;

    double whenWillBeHitBy(Point start, Point dir) const;
    double whenWillBeHitByWithOffset(Point start, Point dir) const;

private:
    const model::Unit& unit_;
};

#endif // IUNIT_HPP
