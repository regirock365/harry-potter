#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include <iostream>
#include <string>

int main(){
	wizard player1= wizard("Harry","Gryffindor");
	wizard player2= wizard("Draco", "Slytherin");
	expelliarmus spell1 = expelliarmus("Expelliarmus",10);

	player1.getName();
	std::cout<<player1.getHealth()<<std::endl;

	std::cout<<spell1.castSpell(player1).getHealth()<<std::endl;
};
