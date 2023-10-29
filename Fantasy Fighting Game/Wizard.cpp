#include "Wizard.h"
#include <iostream>
#include <string>
#include <cstdlib>

Wizard::Wizard(std::string n) : Player(n, 100, 12, 4) {} //Health = 100, Default attack = 12, Default defense = 10

void Wizard::chooseAbility(int choice)
{
    int chance;
    switch (choice) {
    case 1:
        attack += 5; // Wand: Increase attack by 5
        break;
    case 2:
        chance = rand() % 100 + 1;
        if (chance > 90) {
            attack += rand() %10 + 8; //Spell book: Critical hit (8-10)
        }
        else {
            attack += rand() %6 + 1; // Spell Book: Increase attack (1-6)
        }
        break;
    case 3:
        attack += rand() %7 + 5; // Rod: Increase attack (5-7)
        break;
    default:
        // Invalid choice
        std::cout << "Not a valid choice." << std::endl;
        attack += 0;
        break;
    }
}

void Wizard::resetAttack(){
    attack = 12;
}

void Wizard::displayAbilities() {
    std::cout << "Wizard Abilities:" << std::endl;
    std::cout << "1. Wand - A small, handheld magical implement used for spellcasting." << std::endl;
    std::cout << "2. Spell Book - A grimoire or magical tome containing spells and incantations." << std::endl;
    std::cout << "3. Rod - A slender, elongated magical instrument often used for directing energy." << std::endl;
}

