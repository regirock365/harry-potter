#ifndef STUPEFY_H
#define STUPEFY_H

#include "spell.h"


class stupefy : public spell
{
public:
	stupefy(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~stupefy();
};

#endif