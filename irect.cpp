#include "irect.hpp"

IRect::IRect() :
    model::Unit(0,0,0,0,0,0,0,0,0),
    IUnit((model::Unit)*this)

{
}
