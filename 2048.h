#ifndef _2048_H
#define _2048_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <math.h>
#include <termios.h>

#define VK_LEFT 	(97)
#define VK_UP 		(119)
#define VK_RIGHT 	(100)
#define	VK_DOWN 	(115)
#define VK_QUIT		(113)

int table[16];

int init();

void show();

int random_position();

void handle(char VK);

int check_zero();

int check_alive();

char getch_from_terminal();

#endif /*<_2048_H>*/