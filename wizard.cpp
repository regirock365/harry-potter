#include <iostream>
#include "wizard.h"
#include <string>

wizard::wizard(std::string aName, std::string aHouse){
	name = aName;
	house = aHouse;
	health = 100.0;
}

void wizard::setHealth(float aHealth){
	health = aHealth;
}

void wizard::getName(){
	std::cout << name <<std::endl;
}

void wizard::getHouse(){
	std::cout << house << std::endl;
}

float wizard::getHealth(){
	return health;
}