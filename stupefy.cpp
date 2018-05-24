#include "stupefy.h"
#include "spell.h"
#include "wizard.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <string>
using namespace std;

stupefy::stupefy(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void stupefy::castSpell(wizard* castOn, wizard* caster){
	//creating a random number based on time
	srand(time(0));
	int x = rand()%10;
	std::cout << "\e[1mSTUPEFY\e[0m" << std::endl; //bold spell output to simulate yelling
	//forcing the attack to be 80% chance miss rate
	if(x<2){
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-d*Damage;
		castOn->setHealth(h);
		std::cout << "Successful Attack." << std::endl;

	}
	else{
		std::cout << "Attack missed" << std::endl;
	}
}


stupefy::~stupefy(){

}

