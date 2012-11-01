#ifndef DRIVESTRATEGY_HPP
#define DRIVESTRATEGY_HPP

#include <cmath>

#include "istrategy.hpp"

class DriveStrategy : public IStrategy
{
public:
    DriveStrategy();

    virtual Action makeDecision(ITank &tank, model::World world);
    void moveTo(ITank &tank, double x, double y, Action &action);
};

#endif // DRIVESTRATEGY_HPP
