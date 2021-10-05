#define _CRT_SECURE_NO_WARNINGS 1
#include "add.h"



void game()
{
	int i = 0;
	int j = 0;
	char board[ROW][COL] = { 0 };
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			board[i][j] = ' ';
	}
	int stat = 0;
	show(board);
	do
	{
		player(board);
		exam(board, &stat);
		if (stat == 1||stat==3)
		{
			show(board);
			break;
		}
		computer(board);
		show(board);
		exam(board,&stat);
	} while (!stat);
	switch (stat)
	{
	case 1:
		printf("you win\n");
		break;
	case 2:
		printf("you lose\n");
		break;
	case 3:
		printf("Æ½¾Ö\n");
		break;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int chs = 0;
	do
	{
		
		menu();
		printf("ÇëÑ¡Ôñ;");
		flag:
		scanf("%d", &chs);
		switch (chs)
		{
		case 0:
			printf("game start\n");
			game();
			break;
		case 1:
			printf("exit");
			break;
		default:
			printf("wrong,choose again:");
			goto flag;
		}
	} while(!chs);
	

	return 0;
}