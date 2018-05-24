#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include "harry.h"
#include "draco.h"
#include <ctype.h>
#include <iostream>
#include "gui.h"
#include <unistd.h>


extern bool validMove(int move, gui* terminal);
extern bool endGame(wizard obj, int move, int player, gui* terminal);
extern bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3, gui* terminal);
extern void playGame(gui* terminal);

int main(){

	gui* terminal = new gui(30,100);

	terminal -> print(1, "Welcome to the Harry Potter fight club", "middle");
	terminal -> print(2, "Rules", "left");
	terminal -> print(3, "Press 1 for Spell Expelliarmus. This is an accurate, low damage spell.", "left");
	terminal -> print(4, "Press 2 for Spell Protego. This is a defensive spell that increases health.", "left");
	terminal -> print(5, "Press 3 for Spell Stupefy. This is a powerful attacking spell with low accuracy.", "left");
	terminal -> print(6, "Press 4 to Forefeit Match", "left");
	playGame(terminal);
	delete terminal;


	return 0;
}

