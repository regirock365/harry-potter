#ifndef IMPEDIMENTA_H
#define IMPEDIMENTA_H

#include "spell.h"


class impedimenta : public spell
{
public:
	impedimenta(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~impedimenta();
};

#endif