#pragma once

#ifndef Inventory_H
#define Inventory_H

#include <vector>
#include "Potions.h"

class Inventory {
private:
    std::vector<Potions> potions;
public:
    void addPotion(const Potions& potion);
    void removePotion(int index);
    size_t size() const;
    const Potions& operator[](size_t index) const;
    Potions& operator[](size_t index);
    bool empty() const;
};

#endif // Inventory_H
