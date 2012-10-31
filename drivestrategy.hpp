#ifndef DRIVESTRATEGY_HPP
#define DRIVESTRATEGY_HPP

#include "istrategy.hpp"

class DriveStrategy : public IStrategy
{
public:
    DriveStrategy();

    virtual Action makeDecision(ITank &tank, model::World world);
};

#endif // DRIVESTRATEGY_HPP
