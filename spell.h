#ifndef SPELL_H
#define SPELL_H
#include "wizard.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <string>

class spell
{
public:
	spell(std::string spellName, float aDamage); //constructor
	virtual void castSpell(wizard* castOn, wizard* caster)=0; //play 
	~spell(); //deconstructor

protected:
	//attributes
	std::string spellName;
	float Damage;
};

#endif 