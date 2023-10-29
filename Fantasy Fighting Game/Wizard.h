#pragma once

#ifndef Wizard_H
#define Wizard_H

#include <string>
#include "Player.h"

class Wizard : public Player {
public:
    Wizard(std::string n);

    //Fighting Functions
    void chooseAbility(int choice) override;
    void resetAttack() override;
    void displayAbilities() override;

    //Shopping Functions
    //void shopWeapons() override;
    //void shopArmor() override;
};

#endif Wizard_H