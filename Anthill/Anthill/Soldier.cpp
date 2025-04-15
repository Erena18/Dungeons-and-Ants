#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Soldier.h"

using namespace std;

void Soldier::Eat(Ant& ant, Food& food)
{
    int foodRequired = 20;
    int hpLossWithoutFood = 15;
    int hpRestoreAfterEating = 30;

    int consumed = food.consume(foodRequired);
    if (consumed > 0)
    {
        ant.restoreHp(hpRestoreAfterEating);
    }
    else
    {
        ant.loseHp(hpLossWithoutFood);
    }
}

void Soldier::Work()
{
        if (hp <= 0) return;
        if (has_target) {
            float dx = target.x - pos.x;
            float dy = target.y - pos.y;
            float dist = sqrt(dx * dx + dy * dy);
            if (dist > 5.f) {
                velocity.x = (dx / dist) * ant_speed;
                velocity.y = (dy / dist) * ant_speed;
            }
            else {
                pos.x = target.x;
                pos.y = target.y;
                velocity.x = 0;
                velocity.y = 0;
                if (inventory != no_res && !pos.in_anthill()) {
                    set_target(Position(window_width / 2, window_height / 2));
                    going_home = true;
                }
                else if (inventory != no_res && pos.in_anthill()) {
                    if (inventory == food) Anthill::add_food();
                    else if (inventory == stick) Anthill::add_stick();
                    inventory = no_res;
                    clear_target();
                    going_home = false;
                }
                else has_target = false;
            }
            pos.x += velocity.x;
            pos.y += velocity.y;
            shape.setPosition(pos.x, pos.y);
        }
        else {
            if (role_id == 0) return;
            if (role_id != 1) {
                if (age % velocity_changing_period == 0) set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
                if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_width) velocity.x = -velocity.x;
                if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_height) velocity.y = -velocity.y;
            }
            else {
                if (age % (velocity_changing_period * 2) == 0) set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
                if (pos.x + velocity.x < window_width / 2 - 2 * start_radius || pos.x + velocity.x > window_width / 2 + 2 * start_radius)velocity.x = -velocity.x;
                if (pos.y + velocity.y < window_height / 2 - 2 * start_radius || pos.y + velocity.y > window_height / 2 + 2 * start_radius) velocity.y = -velocity.y;
            }
            pos.x += velocity.x;
            pos.y += velocity.y;
            shape.setPosition(pos.x, pos.y);
        }
    }
}