#include "gui.h"

#include <ncurses.h>
#include <unistd.h>
#include <string>

gui::gui(int h, int w) {
	initscr();
	noecho();
	height = h;
	width = w;
	win = newwin(height, width, 1, 1);
	refresh();

	box(win, '*', '*');
	this->refresh();
}

void gui::move(int y, int x) {
	wmove(win, y,x);
	// this->refresh();
}

void gui::print(int line, std::string text, std::string position) {
	int x = 1;
	if (position == "middle") {
		x = (width - text.size()) / 2;
	} else if (position == "right") {
		x = width - text.size() - 1;
	}

	this->move(line, 1);
	wclrtoeol(win);
	this->move(line, x);
	wprintw(win, text.c_str());
	this->refresh();
	flushinp();
	sleep(1);
	// this->get();
}

int gui::get() {
	int c = wgetch(win);
	int output = 0;

	switch(c) {
		case 49:
			output = 1;
			break;
		case 50:
			output = 2;
			break;
		case 51:
			output = 3;
			break;
		case 52:
			output = 4;
			break;
	}

	return output;
	// this->refresh();
}

int gui::getHeight() {
	return height;
}

int gui::getWidth() {
	return width;
}

void gui::clearLine(int line) {
	this->move(line, 1);
	wclrtoeol(win);
}

void gui::refresh() {
	wrefresh(win);
}

gui::~gui() {
	endwin();
}