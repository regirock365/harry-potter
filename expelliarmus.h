#ifndef EXPELLIARMUS_H
#define EXPELLIARMUS_H

#include "spell.h"
#include <vector>

class expelliarmus : public spell
{
public:
	
	void castSpell(wizard obj1);
	~expelliarmus();
};

#endif