#ifndef GUI_H
#define GUI_H

#include <ncurses.h>
#include <string>

class gui
{
public:
	gui(int h, int w);
	void print(int line, std::string text, std::string position);
	int get();
	int getHeight();
	int getWidth();
	void clearLine(int line);
	~gui();

private:
	WINDOW * win;
	int height;
	int width;

	void refresh();
	void move(int y, int x);
};

#endif