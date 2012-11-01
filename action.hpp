#ifndef IACTION_HPP
#define IACTION_HPP

#include "model/Move.h"

class Action
{
public:
    Action();

    void setLeft(double);
    void setRight(double);
    void setTurretRotate(double);
    void setFireType(model::FireType);

    void applyAction(model::Move &);

private:
    double left, right, turretRotate;
    model::FireType fireType;

};

#endif // IACTION_HPP
