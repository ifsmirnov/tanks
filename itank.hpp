#ifndef ITANK_HPP
#define ITANK_HPP

#include "model/Unit.h"
#include "model/Tank.h"
#include "iunit.hpp"
#include "geom.hpp"

class ITank : public IUnit
{
public:
    ITank(const model::Tank &tank);

    const model::Tank tank() const;

    operator model::Tank() const;

    int health() const;
    int armour() const;
    int maxHealth() const;
    int maxArmour() const;
    int frontArmour() const;
    int rearArmour() const;
    int sideArmour() const;
    bool isTeammate() const;
    int teammateIndex() const;
    bool isDead() const;
    model::TankType type() const;

    int remainingReloadTime() const;
    int reloadTime() const;
    double turretRelativeAngle() const;
    double turretAbsoluteAngle() const;
    double turretMaxRelativeAngle() const;
    double turretTurnSpeed() const;
    double turretAngleTo(double x, double y) const;
    double turretAngleTo(const model::Unit & unit) const;
    int premiumShellCount() const;
    double gunLength() const;
    Point gunEndpoint() const;

    double mass() const;
    double enginePower() const;
    double rearFactor() const;

private:
    const model::Tank &tank_;
};

#endif // ITANK_HPP
