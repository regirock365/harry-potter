#include "gui.h"

#include <ncurses.h>
#include <string>
using namespace std;

int main(int argc, char ** argv) {
	// // initializes the screen
	// // sets up memory and clears the screen
	// initscr();

	// int height, width, start_y, start_x;
	// height = 20;
	// width = 40;
	// start_y = start_x = 1;

	// // window pointer called win
	// WINDOW * win = newwin(height, width, start_y, start_x);
	// refresh();

	// endwin();

	gui * terminal = new gui(20, 40);

	// terminal->move(1,1);
	// terminal->get();
	// terminal->print("Harry Potter!!");
	// terminal->print(2, "!!");
	terminal->print(3, "Welcome To Harry Potter");
	terminal->print(3, "The rules are simple");
	terminal->print(3, "don't lose :)");
	// terminal->print(3, "11");

	delete terminal;

	return 0;
}