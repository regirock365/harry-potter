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
extern bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3);
extern void playGame(gui* terminal);

int main(){

	gui* terminal = new gui(30,50);

	terminal -> print(1, "Welcome to the Harry Potter fight club", "middle");
	terminal -> print(2, "Rules", "left");
	terminal -> print(3, "g;f", "right");
	playGame(terminal);
	delete terminal;


	return 0;
}

