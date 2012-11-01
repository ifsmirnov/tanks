#ifndef ISTRATEGY_HPP
#define ISTRATEGY_HPP

#include "model/Tank.h"
#include "model/World.h"

#include "action.hpp"
#include "itank.hpp"

#include "geom.hpp"

#include <cmath>

class IStrategy
{
public:
    IStrategy();
    virtual ~IStrategy();

    virtual Action makeDecision(ITank& tank, model::World world);

protected:
    double todeg(double rad);
    double torad(double deg);
};

#endif // ISTRATEGY_HPP
