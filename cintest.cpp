#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include "harry.h"
#include "draco.h"
#include <ctype.h>
#include <iostream>
#include <unistd.h>


bool validMove(int move);
bool endGame(wizard obj, int move, int player);
bool playerAttack(int move, int player, wizard player1, wizard player2, expelliarmus spell1, protego spell2, stupefy spell3);
void playGame();

int main(){
	
	playGame();

	return 0;
}



void playGame(){
	std::cout << "//-------------------------------------------------//" << std::endl;
	std::cout << "//                                                 //" << std::endl;
	std::cout << "//                                                 //" << std::endl;
	std::cout << "//    Welcome To the Harry Potter Duelling Club    //" << std::endl;
	std::cout << "//                                                 //" << std::endl;
	std::cout << "//                                                 //" << std::endl;
	std::cout << "//-------------------------------------------------//" << std::endl;
	int move = 0;
	wizard player1 = wizard("Harry","Gryff");
	wizard player2 = wizard("Draco","sl");
	expelliarmus spell1 = expelliarmus("expelliarmus",10);
	protego spell2 = protego("protego",0.1);
	stupefy spell3 = stupefy("stupefy",10);

	std::cout << player1.getName() << " Vs. " << player2.getName() << std::endl;
	std::cout << std::endl;

	sleep(1);
	bool gameRunning = 1;
	bool isValid = 1;
	int player = 2; //2 makes it start on player 1
	while(gameRunning == true){
	 	if(player == 2){
	 		player = 1;
	 	}
	 	else{
	 		player = 2;
	 	}
	 	std::cout << "Player " << player << " it is your turn to attack" << std::endl;
	 
		std::cin >> move;
		isValid = validMove(move);
		if(isValid == 1){
			if(player == 1){
				gameRunning = endGame(player2, move, player);
				std::cout << "Player 2 health: " <<  player2.getHealth() << std::endl;
				gameRunning = playerAttack(move, player, player1, player2, spell1, spell2, spell3);
			}
			else{
				gameRunning = endGame(player1, move, player);
				std::cout << "Player 1 health: " <<  player1.getHealth() << std::endl;
				gameRunning = playerAttack(move, player, player1, player2, spell1, spell2, spell3);	
			}
		}
		else{
			isValid = false;
		}


	}
}


bool validMove(int move){
	if(move <1 || move > 5 || std::cin.fail() ){
		    std::cin.clear();
   			std::cin.ignore(1000,'\n');
		std::cout << "There is no room for mistakes in a duel and";
		std::cout << " your move has been skipped" << std::endl;
		std::cout << "Nothing personnel kiddo" << std::endl;
		return false;
	}
	else if(move == 4){
		std::cout << "lmao really kid?? " << std::endl;
		return true;
	}

	else{
		std::cout << "Successful attack" << std::endl;
		return true;
	}
}

bool playerAttack(int move, int player, wizard player1, wizard player2, expelliarmus spell1, protego spell2, stupefy spell3){
	if(player == 1 & move>0 && move <4){
		if(move == 1){
			spell1.castSpell(player2).getHealth();
		}
		else if(move == 2){
			spell2.castSpell(player2, player1).getHealth();
		}
		else if(move == 3){
			spell3.castSpell(player2, player1).getHealth(); 
		}
		return true;
	}
	else if(player == 2 & move>0 && move<4){
				if(move == 1){
			spell1.castSpell(player1).getHealth();
		}
		else if(move == 2){
			spell2.castSpell(player1, player2).getHealth();
		}
		else if(move == 3){
			spell3.castSpell(player1, player2).getHealth(); 
		}
		return true;
	}
	else{
		return false; //entered exit condition 5 (or last number)
		//ends game
	}
}

bool endGame(wizard obj, int move, int player){
	if(obj.getHealth()<=0){
		std::cout << "Player "  << " has fainted!" << std::endl;
		return false;
	}
	else if(move == 4){
		std::cout << "Player " << player << " has for resigned!" << std::endl;
		return false;
	}
	else{
		return true;
	}
}

