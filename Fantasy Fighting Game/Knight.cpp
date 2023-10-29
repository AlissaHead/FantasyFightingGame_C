#include "Knight.h"
#include <iostream>
#include <string>
#include <cstdlib>

Knight::Knight(std::string n) : Player(n, 100, 10, 6) {} //Health = 100, Default attack = 10, Default defense = 15

void Knight::chooseAbility(int choice)
{
    switch (choice) {
    case 1:
        attack += rand() %7 + 6; // Iron Sword: Increase attack (6-7)
        break;
    case 2:
        attack += rand() %6 + 4; // Dagger: Increase attack (4-6)
        break;
    case 3:
        attack += rand() %8 + 6; // Lance: Increase attack (6-8)
        break;
    default:
        // Invalid choice
        std::cout << "Not a valid choice." << std::endl;
        attack += 0;
        break;
    }
}

void Knight::resetAttack() {
    attack = 10;
}

void Knight::displayAbilities() {
    std::cout << "Knight Abilities:" << std::endl;
    std::cout << "1. Iron Sword - Every Knight's best friend." << std::endl;
    std::cout << "2. Dagger - A smaller blade, useful for close-quarters combat or as a secondary weapon." << std::endl;
    std::cout << "3. Lance - A long spear designed for mounted combat. It's used in jousting or charging on horseback." << std::endl;
}
