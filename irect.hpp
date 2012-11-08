#ifndef IRECT_HPP
#define IRECT_HPP

#include "model/Unit.h"
#include "iunit.hpp"

class IRect : public model::Unit, public IUnit
{
public:
    IRect();
    IRect(Point pos);
};

#endif // IRECT_HPP
