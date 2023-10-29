#include "Archer.h"
#include <iostream>
#include <string>
#include <cstdlib>

Archer::Archer(std::string n) : Player(n, 100, 10, 7) {} //Health = 100, Default attack = 10, Default defense = 16

void Archer::chooseAbility(int choice)
{
    switch (choice) {
    case 1:
        attack += rand() %3 + 1; // Sling shot: Increase attack (1-3)
        break;
    case 2:
        attack += rand() %7 + 4; // Pocket knife: Increase attack (4-7)
        break;
    case 3:
        attack += rand() %6 + 5; // Lance: Increase attack (5-6)
        break;
    default:
        // Invalid choice
        std::cout << "Not a valid choice." << std::endl;
        attack += 0;
        break;
    }
}

void Archer::resetAttack() {
    attack = 10;
}

void Archer::displayAbilities() {
    std::cout << "Archer Abilities:" << std::endl;
    std::cout << "1. Sling Shot - A simple ranged weapon using a small pouch or sling to propel a projectile (usually a stone)." << std::endl;
    std::cout << "2. Pocket Knife - A smaller blade, useful for close-quarters combat or as a secondary weapon." << std::endl;
    std::cout << "3. Bow - The primary weapon of an archer." << std::endl;
}
