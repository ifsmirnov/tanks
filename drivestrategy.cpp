#include "drivestrategy.hpp"

#include <vector>
#include <iostream>

DriveStrategy::DriveStrategy()
{
}

Action DriveStrategy::makeDecision(ITank &tank, model::World world)
{
    Action action;
    action.setLeft(0);
    action.setRight(0);

    std::vector<model::Bonus> bonuses = world.bonuses();
    if (bonuses.empty())
        return action;
    model::Bonus best = bonuses[0];
    for (int i = 1; i < (int)bonuses.size(); i++)
    {
        model::Bonus cur = bonuses[i];
        if (tank.GetDistanceTo(cur) < tank.GetDistanceTo(best))
            best = cur;
    }
    //std::cerr << "Move to " << best.x() << " " << best.y() << std::endl;
    moveTo(tank, best.x(), best.y(), action);
    return action;
}

void DriveStrategy::moveTo(ITank &tank, double x, double y, Action &action)
{
    double angle = tank.GetAngleTo(x, y);
    //std::cerr << "angle = " << todeg(angle) << std::endl;
    if (fabs(todeg(angle)) < 15)
    {
        action.setLeft(1.0);
        action.setRight(1.0);
    }
    else if (fabs(angle) < M_PI / 2.0)
    {
        double left = std::max(1.0, tank.rearFactor() * 1.5);
        double right = -1.0;
        if (angle < 0)
            std::swap(left, right);
        action.setLeft(left);
        action.setRight(right);
    }
    else if (angle < 0)
    {
        action.setLeft(-1);
        action.setRight(tank.rearFactor());
    }
    else
    {
        action.setRight(-1);
        action.setLeft(tank.rearFactor());
    }
}
