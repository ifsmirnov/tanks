#include "action.hpp"

Action::Action()
{
    left = right = turretRotate = 10000;
    fireType = model::UNKNOWN_FIRE;
}

void Action::setFireType(model::FireType fireType_) { fireType = fireType_; }
void Action::setLeft(double val) { left = val; }
void Action::setRight(double val) { right = val; }
void Action::setTurretRotate(double val) { turretRotate = val; }

void Action::applyAction(model::Move &move)
{
    if (left < 100)
        move.set_left_track_power(left);
    if (right < 100)
        move.set_right_track_power(right);
    if (turretRotate < 100)
        move.set_turret_turn(turretRotate);
    if (fireType != model::UNKNOWN_FIRE)
        move.set_fire_type(fireType);
}
