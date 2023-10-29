#pragma once

#ifndef Player_H
#define Player_H

#include <string>
#include "Inventory.h"

class Player {
private: 

	//ATTRIBUTES
	std::string name;
	int healthPts; //If equal or less than 0 player is dead
	int defense; //Has a default for first round and is overrided by buying defenses
	std::string className; //ClassName attribute exclusively allows player to see the store item of their class
	Inventory inventory;

	//COUNTERS
	int wins;
	int damageDone;
	int damageTaken;
	int money = 0; //Money comes into use after first round. Player is given money for total damage done

protected:
	int attack; //Has a default for first round and is overrided by buying weapons or attacks

public:
	Player(std::string n, int h, int a, int d);

	//Class Overrides
	virtual void chooseAbility(int choice) = 0;
	virtual void displayAbilities() = 0;
	virtual void resetAttack();
	virtual void takeDamage(int damage);

	//Round Resets
	void updateHealth(int h);
	int updateMoney(); //Add method to update money
	void addMoney(int amount);

	//Shop functions
	void shop();
	void displayShops();
	//virtual void shopWeapons() = 0;
	//virtual void shopArmor() = 0;
	void shopPotions();

	void usePotion(int potionIndex);
	Inventory& getInventory();

	void loseHP(int damage);
	

	//Getters
	std::string getClassName(); // Add a method to get the class name
	std::string getName();
	int getHealthPoints();
	int getMoney();
	int getWins();
	int getAttack();
	int getDefense();

	virtual ~Player();
};

#endif Player_H