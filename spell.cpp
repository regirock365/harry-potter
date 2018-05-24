#include "spell.h"
#include <string>
#include <iostream>
//#include "wizard.h"
using namespace std;

//implementation of constructor

spell::spell(string aName, float aDamage){
	spellName= aName;
	Damage= aDamage;
}

//castSpell function that other functions will implement
void spell::castSpell(wizard* castOn, wizard* caster){
	
}

//deconstructor
spell::~spell(){}