#ifndef STUPEFY_H
#define STUPEFY_H

#include "spell.h"
#include <string>


class stupefy : public spell
{
public:
	stupefy(std::string aName, float aDamage);
	void castSpell(wizard* castOn, wizard* caster); //deal damage spell
	~stupefy();
};

#endif