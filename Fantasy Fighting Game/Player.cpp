#include "Player.h"
#include "Inventory.h"
#include "Potions.h"
#include <iostream>
#include <vector>

// Constructor
Player::Player(std::string n, int h, int a, int d)
    : name(n), healthPts(h), attack(a), defense(d),
    wins(0), damageDone(0), damageTaken(0), money(0) {}

// Take damage function
void Player::takeDamage(int damage) {
    healthPts -= damage;
    if (healthPts <= 0) {
        healthPts = 0;
        std::cout << name << " has been defeated." << std::endl;
    }
}

std::string Player::getClassName() {
    return className;
}

// Getter methods
std::string Player::getName() {
    return name;
}

int Player::getHealthPoints() {
    return healthPts;
}

int Player::getMoney() {
    return money;
}

int Player::getWins() {
    return wins;
}

int Player::getAttack() {
    return attack;
}

int Player::getDefense()
{
    return defense;
}

void Player::updateHealth(int h)
{
    if(healthPts <= 0){
        healthPts = 100;
    }else{
        healthPts += h;
    }
}

void Player::resetAttack()
{
    //Implementation will be provided in derived classes
}

int Player::updateMoney()
{
    int money = 0;

    if (healthPts <= 0) {
        money = 10; //Default money added will be 10
    }
    else {
        money = (healthPts + 10); //Winner are rewarded for health kept plus the default
    }

    return money;
}

void Player::addMoney(int amount)
{
    money += amount;
}


void Player::shop()
{
    bool shopping = true;

    while (shopping) {
        int section;
        displayShops();
        std::cin >> section;

        switch (section) {
        case 1:
            //shopWeapons();
            break;
        case 2:
            //shopArmor();
            break;
        case 3:
            shopPotions();
            break;
        case 0:
            shopping = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void Player::displayShops()
{
    std::cout << name << " now has " << money << std::endl;
    std::cout << "                                         " << std::endl;
    std::cout << name << ", would you like to shop?\nEnter the number of the shop you wish to enter." << std::endl;
    std::cout << "1. Weapons - Buy new weapons based off of your class." << std::endl;
    std::cout << "2. Armor - Buy upgraded armor based off your class." << std::endl;
    std::cout << "3. Potions - Available for all classes to temporarily upgrade stats." << std::endl;
    std::cout << "Enter 0 to exit shop." << std::endl;
}

void Player::shopPotions() {
    std::vector<Potions> availablePotions = {
        Potions("Health Potion", "Gives player 40 hp.",40, false, 40),
        Potions("Harming Potion", "Takes 10 of oponents hp.",25, true, 10)
    };

    // Display available potions and their prices
    for (size_t i = 0; i < availablePotions.size(); ++i) {
        std::cout << i + 1 << ". " << availablePotions[i].getName() << " - " << availablePotions[i].getInfo() << " costs - " << availablePotions[i].getPrice() << " rockles." << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the potion you want to buy (or 0 to exit): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= availablePotions.size()) {
        Potions chosenPotion = availablePotions[choice - 1];

        if (money >= chosenPotion.getPrice()) {
            money -= chosenPotion.getPrice(); // Deduct the price from player's money
            getInventory().addPotion(chosenPotion); // Assuming you have an inventory to hold potions
            std::cout << "You bought a " << chosenPotion.getName() << "." << std::endl;
        }
        else {
            std::cout << "You don't have enough money to buy this potion." << std::endl;
        }
    }
}

void Player::usePotion(int potionIndex) {
    if (potionIndex >= 0 && potionIndex < inventory.size()) {
        getInventory()[potionIndex].applyEffect(this);
        getInventory().removePotion(potionIndex);; // Remove the used potion from the inventory
    }
}

Inventory& Player::getInventory()
{
    return inventory;
}
// Helper function for losing health points
void Player::loseHP(int damage) {
    healthPts -= damage;
    if (healthPts <= 0) {
        healthPts = 0;
        std::cout << name << " has been defeated." << std::endl;
    }
}


// Destructor
Player::~Player() {
    // Perform any necessary cleanup here
}