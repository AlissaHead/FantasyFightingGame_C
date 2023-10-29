#include "Potions.h"
#include "Player.h"

#include <iostream>

// Constructor
Potions::Potions(std::string n, std::string i, int p, bool h, int e)
    : name(n), info(i), price(p), harmful(h), effectValue(e) {
}

void Potions::applyEffect(Player* player)
{
    if (!harmful) {
        // If it's not a harmful potion (e.g., health potion), increase player's health
        player->updateHealth(effectValue);
        std::cout << "Player regained health!" << std::endl;
    }
    else {
        // If it's a harmful potion, deal damage to the player
        player->takeDamage(effectValue);
        std::cout << player->getName() << " took damage!" << std::endl;
    }
}

// Getters
std::string Potions::getName() {
    return name;
}

std::string Potions::getInfo() {
    return info;
}

int Potions::getPrice() {
    return price;
}

bool Potions::isHarmful() {
    return harmful;
}

int Potions::AttributeChange() {
    return effectValue;
}

// Destructor (if needed)
Potions::~Potions() {
    // Add cleanup code if necessary
}
