#include "gui.h"

#include <ncurses.h>
#include <string>

gui::gui(int h, int w) {
	initscr();
	win = newwin(h, w, 1, 1);
	print(h - 2, "Press 'Enter' to continue");
	refresh();

	box(win, '*', '*');
	this->refresh();
	getchar();
	// wprintw(win, "HARRY POTTER!!!");
	// refresh a specific window

	// waits for user input, returns int value of that key
	// int c = getch();
}

void gui::move(int y, int x) {
	wmove(win, y,x);
	this->refresh();
}

void gui::print(int line, std::string text) {
	this->move(line, 1);
	wclrtoeol(win);
	wprintw(win, text.c_str());
	this->refresh();
	this->get();
}

void gui::get() {
	int c = wgetch(win);
	// this->refresh();
}

void gui::refresh() {
	wrefresh(win);
}

gui::~gui() {
	endwin();
}