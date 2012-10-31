#ifndef ISTRATEGY_HPP
#define ISTRATEGY_HPP

#include "model/Tank.h"
#include "model/World.h"

#include "action.hpp"

class IStrategy
{
public:
    IStrategy();
    virtual ~IStrategy();

    virtual Action makeDecision(model::Tank tank, model::World world);
};

#endif // ISTRATEGY_HPP
