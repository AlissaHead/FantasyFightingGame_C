#include "Inventory.h"

void Inventory::addPotion(const Potions& potion) {
    potions.push_back(potion);
}

void Inventory::removePotion(int index) {
    if (index >= 0 && index < potions.size()) {
        potions.erase(potions.begin() + index);
    }
}

size_t Inventory::size() const {
    return potions.size();
}

const Potions& Inventory::operator[](size_t index) const {
    return potions[index];
}

Potions& Inventory::operator[](size_t index) {
    return potions[index];
}

bool Inventory::empty() const {
    return potions.empty();
}

