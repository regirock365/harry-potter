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
	c=c-Damage;
	h=h+10;

	//check if defense has gotten too strong
	if(c>0.5){
		caster->setDefense(c);
	}	
	if(h<90){
		caster->setHealth(h);
	}
	//return caster;
}

protego::~protego(){

}