#ifndef SPELL_H
#define SPELL_H
#include "wizard.h"

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
	virtual wizard castSpell(wizard obj1);

	//setters
	virtual void set_name(std::string aName);
	virtual void set_description(std::string aDescription);
	virtual void set_power(float aPower);
	virtual void set_speed(float aSpeed);
	virtual void set_accuracy(float aAccuracy);

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