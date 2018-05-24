#include "spell.h"
#include <string>
#include <iostream>
//#include "wizard.h"
using namespace std;

//implementation of constructor

spell::spell(string aName, float aDamage){
	spellName= aName;
	description= "";
	Damage= aDamage;
	// Speed;
	// Accuracy;
	// Power;
}

void spell::castSpell(wizard* castOn, wizard* caster, gui* terminal){
	
}

//setters



//deconstructor
spell::~spell(){}