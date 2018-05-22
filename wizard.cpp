#include <iostream>
#include "wizard.h"
#include <string>

wizard::wizard(std::string aName, std::string aHouse){
	name = aName;
	house = aHouse;
	health = 100.0;
	defense = 1;
}

void wizard::setHealth(float aHealth){
	health = aHealth;
}

void wizard::setDefense(float aDefense){
	defense = aDefense;
}

std::string wizard::getName(){
	return name;
}

std::string wizard::getHouse(){
	return house;
}

float wizard::getHealth(){
	return health;
}

float wizard::getDefense(){
	return defense;
}