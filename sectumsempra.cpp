#include "sectumsempra.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

sectumsempra::sectumsempra(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

wizard sectumsempra::castSpell(wizard obj1){
	float c = obj1.getHealth();
	c=c-Damage;
	obj1.setHealth(c);
	return obj1;
}

sectumsempra::~sectumsempra(){

}