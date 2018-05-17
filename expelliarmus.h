#ifndef EXPELLIARMUS_H
#define EXPELLIARMUS_H

#include "spell.h"
#include <vector>

class expelliarmus : public spell
{
public:
	expelliarmus(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~expelliarmus();
};

#endif