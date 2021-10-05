#include<stdio.h>
#include<time.h>
#define COL 3
#define ROW 3


#ifndef __ADD_H__
#define __ADD_H__

void menu();
void player(char board[][COL]);
void computer(char board[][COL]);
void show(char board[][COL]);
void exam(char board[][COL], int* a);
#endif

