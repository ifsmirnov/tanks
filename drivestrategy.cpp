#include "drivestrategy.hpp"

DriveStrategy::DriveStrategy()
{
}

Action DriveStrategy::makeDecision(ITank &tank, model::World world)
{
    Action action;
    action.setLeft(0);
    action.setRight(0);
    return action;
}
