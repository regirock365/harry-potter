#ifndef CRUCIO_H
#define CRUCIO_H

#include "spell.h"


class crucio : public spell
{
public:
	crucio(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~crucio();
};

#endif