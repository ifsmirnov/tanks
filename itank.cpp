#include "itank.hpp"

#include <cmath>

ITank::ITank(const model::Tank &tank) :
    IUnit(tank), tank_(tank) {  }

const model::Tank ITank::tank() const { return tank_; }

ITank::operator model::Tank() const { return tank(); }

std::string ITank::playerName() const { return tank().player_name(); }

int ITank::health() const { return tank().crew_health(); }
int ITank::armour() const { return tank().hull_durability(); }
int ITank::maxArmour() const { return tank().crew_max_health(); }
int ITank::maxHealth() const { return tank().hull_max_durability(); }
int ITank::frontArmour() const { return tank().frontal_armor(); }
int ITank::rearArmour() const { return tank().rear_armor(); }
int ITank::sideArmour() const { return tank().side_armor(); }
bool ITank::isTeammate() const { return tank().teammate(); }
int ITank::teammateIndex() const { return tank().teammate_index(); }
bool ITank::isDead() const { return armour() <= 0 || health() <= 0; }
model::TankType ITank::type() const { return tank().type(); }

int ITank::remainingReloadTime() const { return tank().remaining_reloading_time(); }
int ITank::reloadTime() const { return tank().reloading_time(); }
double ITank::turretRelativeAngle() const { return tank().turret_relative_angle(); }
double ITank::turretAbsoluteAngle() const { return turretRelativeAngle() + angle(); }
double ITank::turretMaxRelativeAngle() const { return tank().turret_max_relative_angle(); }
double ITank::turretTurnSpeed() const { return tank().turret_turn_speed(); }
double ITank::turretAngleTo(double x, double y) const { return tank().GetTurretAngleTo(x, y); }
double ITank::turretAngleTo(const Point &point) const { return tank().GetTurretAngleTo(point.x(), point.y()); }
double ITank::turretAngleTo(const model::Unit &unit) const { return tank().GetTurretAngleTo(unit); }
int ITank::premiumShellCount() const { return tank().premium_shell_count(); }
double ITank::gunLength() const { return tank().virtual_gun_length(); }
Point ITank::gunEndpoint() const
{
    double sina = sin(turretAbsoluteAngle());
    double cosa = cos(turretAbsoluteAngle());
    return pos() + (Point(cosa, sina) * gunLength());
}

double ITank::mass() const { return tank().mass(); }
double ITank::enginePower() const { return tank().engine_power(); }
double ITank::rearFactor() const { return tank().engine_rear_power_factor(); }

