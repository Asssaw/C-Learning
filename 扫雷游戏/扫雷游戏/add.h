#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef __ADD_H__
#define __ADD_H__
void show(char** p, int row, int col);
void judge(char** see, char** hide, int row_choose, int col_choose, int* isdie, int* isover, int row, int col, int num_bomb);

#endif