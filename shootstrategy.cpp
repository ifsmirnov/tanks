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

    TankRec::minAngle = 0;//tank.remainingReloadTime() * tank.turretTurnSpeed(); // TODO

    std::vector<model::Tank> tanks = world.tanks();
    std::vector<TankRec> enemies;

    for (std::vector<model::Tank>::iterator it = tanks.begin(); it != tanks.end(); it++)
    {
        ITank t(*it);
        if (!t.isTeammate() && !t.isDead())
        {
            enemies.push_back(TankRec(tank.turretAngleTo(t),
                                      tank.distanceTo(t),
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
            model::ShellType shellType = tank.premiumShellCount() ? model::PREMIUM : model::REGULAR;
            Point shootPos = tank.gunEndpoint();
            //std::cerr << "gunAngle = " << (shootPos - tank.pos()).angle() << std::endl;
            //std::cerr << "angle = " << tank.angle() << std::endl;
            Point shootVector(cos(tank.turretAbsoluteAngle()), sin(tank.turretAbsoluteAngle()));
            //std::cerr << "pre sV = " << shootVector << std::endl;
            if (shellType == model::REGULAR)
                shootVector *= 16.666667;
            else
                shootVector *= 13.333333;

            std::cerr << "Fail rate: " << todeg(shootVector.angleTo(enemy.pos() - shootPos)) << std::endl;

            double timeToHit = enemy.whenWillBeHitBy(shootPos, shootVector);
            std::cerr << "tth = " << timeToHit << std::endl;
            double angleToEnemy = todeg(tank.turretAngleTo(enemy));
            std::cerr << "aTE = " << angleToEnemy << std::endl;
            if (timeToHit > -0.5)
            //if (abs(todeg(tank.turretAngleTo(enemy))) < 3.0)
            {
                action.setFireType(model::PREMIUM_PREFERRED);
                std::cerr << "Shoot, angle = " << todeg(enemies[0].angle) << std::endl;
                std::cerr << "wwhb = " << timeToHit << std::endl;
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
