#include "iunit.hpp"

IUnit::IUnit(const model::Unit &unit) :
    unit_(unit) {  }

long long IUnit::id() const { return unit_.id(); }
double IUnit::width() const { return unit_.width(); }
double IUnit::height() const { return unit_.width(); }
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
double IUnit::distanceTo(const model::Unit &unit) const { return unit_.GetDistanceTo(unit); }
double IUnit::distanceTo(double x, double y) const { return unit_.GetDistanceTo(x, y); }
