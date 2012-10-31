#include "istrategy.hpp"

IStrategy::IStrategy()
    {  }

IStrategy::~IStrategy()
    {  }

Action IStrategy::makeDecision(model::Tank, model::World)
{
    return Action();
}
