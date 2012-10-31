#ifndef DRIVESTRATEGY_HPP
#define DRIVESTRATEGY_HPP

#include "istrategy.hpp"

class DriveStrategy : public IStrategy
{
public:
    DriveStrategy();

    virtual Action makeDecision(model::Tank tank, model::World world);
};

#endif // DRIVESTRATEGY_HPP
