#pragma once

#ifndef Knight_H
#define Knight_H

#include <string>
#include "Player.h"

class Knight : public Player {
public:
    Knight(std::string n);

    //Fighting Functions
    void chooseAbility(int choice) override;
    void resetAttack() override;
    void displayAbilities() override;

    //Shopping Functions
    //void shopWeapons() override;
    //void shopArmor() override;

    //~Knight() override;
};

#endif Knight_H