#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include <iostream>
#include <string>

int main(){
	wizard player1= wizard("Harry","Gryffindor");
	wizard player2= wizard("Draco", "Slytherin");
	
	player1.getName();
	std::cout<<player1.getHealth()<<std::endl;
	expelliarmus.castSpell(player1);
	std::cout<<player1.getHealth()<<std::endl;
}