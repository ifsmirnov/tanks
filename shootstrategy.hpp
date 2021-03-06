#ifndef SHOOTSTRATEGY_HPP
#define SHOOTSTRATEGY_HPP

#include "istrategy.hpp"

class ShootStrategy : public IStrategy
{
public:
    ShootStrategy();

    Action makeDecision(ITank& tank, model::World world);
};

#endif // SHOOTSTRATEGY_HPP
