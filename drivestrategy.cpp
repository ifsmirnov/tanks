#include "drivestrategy.hpp"

DriveStrategy::DriveStrategy()
{
}

Action DriveStrategy::makeDecision(model::Tank tank, model::World world)
{
    Action action;
    action.setLeft(tank.engine_rear_power_factor());
    action.setRight(-1);
    return action;
}
