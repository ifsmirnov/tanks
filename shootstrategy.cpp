#include "shootstrategy.hpp"

ShootStrategy::ShootStrategy()
{
}

Action ShootStrategy::makeDecision(model::Tank tank, model::World world)
{
    Action action;
    action.setFireType(model::PREMIUM_PREFERRED);
    action.setTurretRotate(100);
    return action;
}
