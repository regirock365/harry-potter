#include <iostream>
#include "wizard.h"
#include <string>
//constructor: initalising a wizard with name, 100 health and 1 defense.
wizard::wizard(std::string aName){
	name = aName;
	health = 100.0;
	defense = 1;
}
//changing the health of a wizard
void wizard::setHealth(float aHealth){
	health = aHealth;
}
//changing the defense of a wizard
void wizard::setDefense(float aDefense){
	defense = aDefense;
}

//retrieving name of a wizard
std::string wizard::getName(){
	return name;
}
//retrieving the health of a wizard
float wizard::getHealth(){
	return health;
}
//retrieving the defense of a wizard
float wizard::getDefense(){
	return defense;
}