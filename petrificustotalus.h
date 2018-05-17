#ifndef PETRIFICUSTOTALUS_H
#define PETRIFICUSTOTALUS_H

#include "spell.h"


class petrificustotalus : public spell
{
public:
	petrificustotalus(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~petrificustotalus();
};

#endif