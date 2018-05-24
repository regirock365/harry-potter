#include "protego.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

protego::protego(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void protego::castSpell(wizard* castOn, wizard* caster){
	float c = caster->getDefense();
	float h = caster->getHealth();
	c=c+0.1;
	h=h+10;
	std::cout << "\e[1mPROTEGO\e[0m" << std::endl; // output bold character
	//check if defense has gotten too strong
	if(c<=2){
		caster->setDefense(c);
		std::cout << caster->getName() << "'s defense has risen to: " << caster->getDefense() << std::endl;
	}	
	caster->setHealth(h);
	std::cout << caster->getName() << "'s health increased to: " <<  caster->getHealth() << std::endl;
	std::cout << std::endl;	
}

protego::~protego(){

}