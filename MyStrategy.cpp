#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <vector>
#include <algorithm>

#include "istrategy.hpp"
#include "drivestrategy.hpp"
#include "shootstrategy.hpp"

using namespace model;


void MyStrategy::Move(Tank tank, World world, model::Move& move)
{
    IStrategy *driver = new DriveStrategy;
    IStrategy *shooter = new ShootStrategy;
    driver->makeDecision(tank, world).applyAction(move);
    shooter->makeDecision(tank, world).applyAction(move);
}

TankType MyStrategy::SelectTank(int, int)
{
    return MEDIUM;
}
