#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace model;
using std::abs;

double minAngle = M_PI / 180;

void MyStrategy::Move(Tank tank, World world, model::Move& move)
{
    std::vector<Bonus> bonuses = world.bonuses();

    int bestId = -1;
    for (int i = 0; i < (int)bonuses.size(); i++)
    {
        double angle = tank.GetAngleTo(bonuses[i]);
        if (abs(angle) <= M_PI / 2.)
        {
            double dist = tank.GetDistanceTo(bonuses[i]);
            double bestDist = bestId == -1 ? 10000 : tank.GetDistanceTo(bonuses[bestId]);
            if (dist < bestDist)
                bestId = i;
        }
    }
    if (bestId == -1)
    {
        move.set_left_track_power(-1);
        move.set_right_track_power(tank.engine_rear_power_factor());
    }
    else
    {
        double angle = tank.GetAngleTo(bonuses[bestId]);
        if (angle > 0)
        {
            move.set_left_track_power(1);
            move.set_right_track_power(M_PI/2-0.2-abs(angle));
        }
        else
        {
            move.set_left_track_power(0);
            move.set_right_track_power(M_PI/2-0.2-abs(angle));
        }
    }

    move.set_turret_turn(0);
    move.set_fire_type(NONE);
}

TankType MyStrategy::SelectTank(int, int)
{
    return MEDIUM;
}
