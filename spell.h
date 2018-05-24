#ifndef SPELL_H
#define SPELL_H
#include "wizard.h"
#include "gui.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <string>

class spell
{
protected:
	//attributes
	std::string spellName;
	std::string description;
	float Damage;
	float Speed;
	float Accuracy;
	float Power;


public:
	//constructor
	spell(std::string spellName, float aDamage);

	//play
	 virtual void castSpell(wizard* castOn, wizard* caster, gui* terminal)=0;

	//deconstructor
	~spell();
};

#endif 