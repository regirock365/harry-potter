#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include <ctype.h>
#include <iostream>
#include "gui.h"
#include <unistd.h>


extern bool validMove(int move);
extern bool endGame(wizard obj, int move, int player);
extern bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3);
extern void playGame();
extern void initGame();

//initialising interferece to display a welcome screen that has the rules on there
//playing the game
int main(){
	initGame();
	playGame();

	return 0;
}

