#pragma once

#include <string>

class Player;

class Potions {
private:
    std::string name;
    std::string info;
    int price;
    bool harmful;
    int effectValue;

public:
    Potions(std::string n, std::string i, int p, bool h, int e);

    // Getters
    std::string getName();
    std::string getInfo();
    int getPrice();
    bool isHarmful();
    int AttributeChange();

    void applyEffect(Player* player);

    ~Potions();
};

