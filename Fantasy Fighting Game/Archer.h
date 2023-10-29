#pragma once

#ifndef Archer_H
#define Archer_H

#include <string>
#include "Player.h"

class Archer : public Player {
public:
    Archer(std::string n);

    //Fighting Functions
    void chooseAbility(int choice) override;
    void resetAttack() override;
    void displayAbilities() override;

    //Shopping Functions
    //void shopWeapons() override;
    //void shopArmor() override;
};

#endif Archer_H