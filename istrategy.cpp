#include "istrategy.hpp"

IStrategy::IStrategy()
    {  }

IStrategy::~IStrategy()
    {  }

Action IStrategy::makeDecision(ITank&, model::World)
{
    return Action();
}

double IStrategy::todeg(double rad)
{
    return rad / M_PI * 180.0;
}
double IStrategy::torad(double deg)
{
    return deg / 180.0 * M_PI;
}
