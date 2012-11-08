#include "shootstrategy.hpp"

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

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

    model::ShellType shellType = tank.premiumShellCount() ? model::PREMIUM : model::REGULAR;
    Point shootPos = tank.gunEndpoint();
    Point shootVector(cos(tank.turretAbsoluteAngle()), sin(tank.turretAbsoluteAngle()));
    if (shellType == model::REGULAR)
        shootVector *= 16.666667;
    else
        shootVector *= 13.333333;

    std::vector<model::Tank> tanks = world.tanks();
    std::vector<TankRec> enemies;

    for (std::vector<model::Tank>::iterator it = tanks.begin(); it != tanks.end(); it++)
    {
        ITank t(*it);
        if (!t.isTeammate() && !t.isDead() && t.playerName() != "EmptyPlayer")
        {
            Point expPos = t.pos() + t.speed() * (shootPos.distanceTo(t.pos()) / shootVector.length());
            enemies.push_back(TankRec(tank.turretAngleTo(expPos),
                                      tank.distanceTo(expPos),
                                      it - tanks.begin()));
        }
    }

    std::sort(enemies.begin(), enemies.end());
    if (!enemies.empty())
    {
        ITank enemy(tanks[enemies[0].id]);
        action.setTurretRotate(tank.turretAngleTo(enemy));

        if (tank.remainingReloadTime() == 0 && world.tick() >= 3)
        {

            double timeToHit = enemy.whenWillBeHitByWithOffset(shootPos, shootVector);
            double angleToEnemy = todeg(tank.turretAngleTo(enemy));
            if (timeToHit > -0.5)
            {
                action.setFireType(model::PREMIUM_PREFERRED);
                std::cerr << "Shoot, angle = " << angleToEnemy << std::endl;
                std::cerr << "wwhb = " << timeToHit << std::endl;
                std::cerr << "real wwhb = " << enemy.whenWillBeHitBy(shootPos, shootVector) << std::endl;
            }
            else
                action.setFireType(model::NONE);
        }
        else
        {
            action.setFireType(model::NONE);
        }
    }
    else
    {
        action.setTurretRotate(0);
        action.setFireType(model::NONE);
    }

    return action;
}
