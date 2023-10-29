#pragma once

#include <string>

class StoreItem {
private:
    std::string name;
    int cost;
    std::string description;
    std::string availableFor;

public:
    StoreItem(std::string name, int cost, std::string description, std::string availableFor);
    std::string getName();
    int getCost();
    std::string getDescription();
    bool isAvailableFor(std::string className);
};
