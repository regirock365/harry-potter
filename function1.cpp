#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include <iostream>
#include <unistd.h>
#include "gui.h"
#include <ctype.h>


/*
validMove tests to see if the user has inputted the character inputs. The values we are taking
are integers between 1 and 4 inclusively. If any other values are inputted we are skipping their attack,
similar to making a mistake in a real duel. 
We are also using sleep to delay inputs to simulate a more natural flowing game.
*/
bool validMove(int move, gui* terminal){
	if(move <1 || move > 5 /*|| std::cin.fail()*/ ){
   		terminal->print(20, "There is no room for mistakes in a duel and...", "left");
   		terminal->print(21, "your move has been skipped", "middle");
   		terminal->clearLine(20);
   		terminal->clearLine(21);
		return false;
	}
	else if(move == 4){
		return true;
	}

	else{
		return true;
	}
}

/*
playerAttack is where we simulate the damage and healing attributes of our game. We test to see which move
was inputted and correspond that to its respect spell. i.e. move 1 is mapped to spell1 etc.
We also test for the player; if player == 1 we use a spell on player 2 and vice verse.
*/
bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3, gui* terminal){
	if(player == 1 & move>0 && move <4){
		if(move == 1){
			terminal->print(13, "EXPELLIARMUS", "left");
			terminal->clearLine(13);
			spell1.castSpell(player2, player1, terminal);
		}
		else if(move == 2){
			terminal->print(13, "PROTEGO", "left");
			terminal->clearLine(13);
			spell2.castSpell(player2, player1, terminal);
		}
		else if(move == 3){
			terminal->print(13, "STUPEFY", "left");
			terminal->clearLine(13);
			spell3.castSpell(player2, player1, terminal); 
		}
		return true;
	}
	else if(player == 2 & move>0 && move<4){
		if(move == 1){
			terminal->print(13, "EXPELLIARMUS", "left");
			terminal->clearLine(13);
			spell1.castSpell(player1, player2, terminal);
		}
		else if(move == 2){
			terminal->print(13, "PROTEGO", "left");
			terminal->clearLine(13);
			spell2.castSpell(player1, player2, terminal);
		}
		else if(move == 3){
			terminal->print(13, "STUPEFY", "left");
			terminal->clearLine(13);
			spell3.castSpell(player1, player2, terminal);
		}
		return true;
	}
	else{
		// entered exit condition 4 (or last number)
		//ends game
		return false;
	}
}

/*
endGame checks for an exit input of 4, or for either wizard to reach health 0 or below.
this ends this game with a message output. of harry/draco resigns and harry/draco was no match 
for draco/harry
*/
bool endGame(wizard obj, int move, int player, gui* terminal){
	if(player == 1 && obj.getHealth()<=0){
		terminal->print(17, "Draco has fainted!", "left");
		terminal->print(18, "Harry is victorious!", "left");
		terminal->get();
		return false;
	}
	else if(player == 2 && obj.getHealth()<=0){
		terminal->print(17, "Harry has fainted!", "right");
		terminal->print(18, "Draco is victorious!", "left");
		terminal->get();
		return false;
	}
	else if(move == 4 && player == 1){
		terminal->print(17, "Harry has resigned!", "right");
		terminal->print(18, "Draco is victorious!", "left");
		terminal->get();
		return false;
	} else if(move == 4 && player == 2){
		terminal->print(17, "Draco has resigned!", "left");
		terminal->print(18, "Harry is victorious!", "left");
		terminal->get();
		return false;
	}
	else{
		return true;
	}
}

/*
playGame uses the logic from the above 3 functions to simulate a working game, in combination with
initialising spell and wizard objets to be used in the duel.
*/
void playGame(gui* terminal){

	int move = 0;
	wizard player1 = wizard("Harry");
	wizard player2 = wizard("Draco");
	expelliarmus spell1 = expelliarmus("expelliarmus",25);
	protego spell2 = protego("protego",0.1);
	stupefy spell3 = stupefy("stupefy",75);

	terminal->print(10,  "Harry Vs. Draco", "middle");

	bool gameRunning = 1;
	bool isValid = 1;
	// 2 makes it start on player 1
	int player = 2;
	while(gameRunning == true){
	 	if(player == 2){
	 		player = 1;
	 	}
	 	else{
	 		player = 2;
	 	}
	 	if(player == 1){
	 	 	terminal->print(11, "Harry it is your turn to attack", "left");	
	 	}
	 	else{
	 	 	terminal->print(11, "Draco it is your turn to attack", "left");	
	 	}

	 
	 	terminal->print(12, "Choose your move: 1, 2, 3, or 4", "left");
	 	// wait for them to choose their move
	 	move = terminal->get();
	 	terminal->clearLine(12);
		isValid = validMove(move, terminal);
		if(isValid == 1){
			if(player == 1){
				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3, terminal);
				if(player2.getHealth() < 0){
					terminal->print(25, "Draco's remaining health: 0", "left");
				}
			}
			else {
				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3, terminal);
				if(player2.getHealth() < 0){
					terminal->print(26, "Harry's remaining health: 0", "left");
				}	
			}
		}
		else {
			isValid = false;
		}
	gameRunning = endGame(player2, move, player, terminal);
	if(!gameRunning){
		break;
	}
	gameRunning = endGame(player1, move, player, terminal);
	if(!gameRunning){
		break;
	}

	}
}

