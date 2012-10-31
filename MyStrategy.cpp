#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <vector>
#include <algorithm>

#include "istrategy.hpp"
#include "drivestrategy.hpp"
#include "shootstrategy.hpp"
#include "itank.hpp"

using namespace model;


void MyStrategy::Move(Tank tank_, World world, model::Move& move)
{
    ITank tank(tank_);
    IStrategy *driver = new DriveStrategy;
    IStrategy *shooter = new ShootStrategy;

    driver->makeDecision(tank, world).applyAction(move);
    shooter->makeDecision(tank, world).applyAction(move);

    delete driver;
    delete shooter; // i'm a fucking manslaughter
}

TankType MyStrategy::SelectTank(int, int)
{
    return MEDIUM;
}
