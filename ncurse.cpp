#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv) {
	// initializes the screen
	// sets up memory and clears the screen
	initscr();

	// prints a string (const char *) to a window
	printw("Hello World!");

	// refreshes the screen to match what's in memory
	refresh();

	// waits for user input, returns int value of that key
	int c = getch();

	printw("%d", c);

	getch();

	endwin();

	return 0;
}