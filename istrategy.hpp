#ifndef ISTRATEGY_HPP
#define ISTRATEGY_HPP

#include "model/Tank.h"
#include "model/World.h"

#include "action.hpp"
#include "itank.hpp"

class IStrategy
{
public:
    IStrategy();
    virtual ~IStrategy();

    virtual Action makeDecision(ITank& tank, model::World world);
};

#endif // ISTRATEGY_HPP
