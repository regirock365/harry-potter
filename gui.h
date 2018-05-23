#ifndef GUI_H
#define GUI_H

#include <ncurses.h>
#include <string>

class gui
{
public:
	gui(int h, int w);
	void move(int y, int x);
	// void print(std::string text);
	void print(int line, std::string text);
	void get();
	~gui();

private:
	WINDOW * win;
	void refresh();
};

#endif