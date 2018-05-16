#include "wizard.h"
#include <string>

wizard::wizard(std::string aName, std::string aHouse){
	name = aName;
	house = aHouse;
	health = -100.0;
}

float wizard::setHealth(float aHealth){
	health = aHealth;
}

void wizard::getName(){
	std::cout << name <<std::endl;
}

void wizard::getHouse(){
	std::cout << house << std::endl;
}

void wizard::getHealth(){
	std::cout << health << std::endl;
}