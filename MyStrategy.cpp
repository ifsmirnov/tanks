#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace model;

void MyStrategy::Move(Tank self, World world, model::Move& move) {
    move.set_left_track_power(-1.0);
    move.set_right_track_power(1.0);
    move.set_turret_turn(M_PI);
    move.set_fire_type(PREMIUM_PREFERRED);
}

TankType MyStrategy::SelectTank(int tank_index, int team_size) {
    return MEDIUM;
}
