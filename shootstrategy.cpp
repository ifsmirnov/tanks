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

Action ShootStrategy::makeDecision(model::Tank tank, model::World world)
{
    Action action;

    TankRec::minAngle = tank.remaining_reloading_time() * tank.turret_turn_speed();

    std::vector<model::Tank> tanks = world.tanks();
    std::vector<TankRec> enemies;

    for (std::vector<model::Tank>::iterator it = tanks.begin(); it != tanks.end(); it++)
    {
        model::Tank t = *it;
        if (!t.teammate())
        {
            enemies.push_back(TankRec(tank.GetTurretAngleTo(t),
                                      tank.GetDistanceTo(t),
                                      it - tanks.begin()));
        }
    }

    std::sort(enemies.begin(), enemies.end());
    if (!enemies.empty())
    {
        action.setTurretRotate(enemies[0].angle);
        if (fabs(enemies[0].angle) < 3.14 / 180 * 5)
            action.setFireType(model::PREMIUM_PREFERRED);
        else
            action.setFireType(model::NONE);
    }
    else
    {
        action.setTurretRotate(0);
        action.setFireType(model::NONE);
    }

    return action;
}
