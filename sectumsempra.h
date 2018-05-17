#ifndef SECTUMSEMPRA_H
#define SECTUMSEMPRA_H

#include "spell.h"


class sectumsempra : public spell
{
public:
	sectumsempra(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~sectumsempra();
};

#endif