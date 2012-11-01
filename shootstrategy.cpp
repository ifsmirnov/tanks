#include "shootstrategy.hpp"

#include <vector>
#include <algorithm>
#include <cmath>

ShootStrategy::ShootStrategy()
{
}

class TankRec
{
public:
    static double minAngle;

    double angle;
    double dist;
    int id;
    TankRec() { }
    TankRec(double angle, double dist, int id):
        angle(angle), dist(dist), id(id) { }

    bool operator< (const TankRec &tr) const
    {
        if (fabs(angle) < minAngle && fabs(tr.angle) < minAngle)
            return dist < tr.dist;
        return std::abs(angle) < std::abs(tr.angle);
    }
};
double TankRec::minAngle = 0;

Action ShootStrategy::makeDecision(ITank &tank, model::World world)
{
    Action action;

    TankRec::minAngle = tank.remainingReloadTime() * tank.turretTurnSpeed();

    std::vector<model::Tank> tanks = world.tanks();
    std::vector<TankRec> enemies;

    for (std::vector<model::Tank>::iterator it = tanks.begin(); it != tanks.end(); it++)
    {
        ITank t(*it);
        if (!t.isTeammate() && !t.isDead())
        {
            enemies.push_back(TankRec(tank.turretAngleTo(t),
                                      tank.GetDistanceTo(t),
                                      it - tanks.begin()));
        }
    }

    std::sort(enemies.begin(), enemies.end());
    if (!enemies.empty())
    {
        action.setTurretRotate(enemies[0].angle);
        if (fabs(todeg(enemies[0].angle) < 3.0))
            action.setFireType(model::PREMIUM_PREFERRED);
        else
            action.setFireType(model::NONE);
        if (world.tick() < 3)
            action.setFireType(model::NONE);
    }
    else
    {
        action.setTurretRotate(0);
        action.setFireType(model::NONE);
    }

    return action;
}
