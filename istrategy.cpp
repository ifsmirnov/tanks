#include "istrategy.hpp"

IStrategy::IStrategy()
    {  }

IStrategy::~IStrategy()
    {  }

Action IStrategy::makeDecision(ITank&, model::World)
{
    return Action();
}
