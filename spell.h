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

	//setters
	 void set_name(std::string aName);
	 void set_description(std::string aDescription);
	 void set_power(float aPower);
	 void set_speed(float aSpeed);
	 void set_accuracy(float aAccuracy);

	//getters
	float get_power();
	float get_speed();
	float get_accuracy();
	std::string get_name();
	std::string get_description();

	//deconstructor
	~spell();
};

#endif 