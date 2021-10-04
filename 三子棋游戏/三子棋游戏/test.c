#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#define COL 3
#define ROW 3

void menu()
{
	printf("***************************\n");
	printf("*****0.play*****1.exit*****\n");
	printf("***************************\n");
}
void player(char board[][COL])
{
	int a = 0;
	int b = 0;
	printf("choose where:");
flag:
	scanf("%d %d", &a, &b);
	if (board[a][b] == ' ' && a < 3 && b < 3)
	{
		board[a][b] = '*';
	}
	
	else
	{
		printf("选择错误，重选：");
		goto flag;
	}

}
void computer(char board[][COL])
{
	int flag = 1;
	do
	{
		int col= 0;
		int row = 0;
		//srand((unsigned int)time(NULL));
		row = rand() % 3;
		//srand((unsigned int)time(NULL));
		col = rand() % 3;
		if (board[row][col]  == ' ')
		{
			board[row][col] ='@';
			flag = 0;
		}
	} while (flag);
}
void show(char board[][COL])
{
	printf("-----------\n");
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
	printf("-----------\n");
}
void exam(char board[][COL],int* a)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '*')
		{
			*a = 1;
		}
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '@')
		{
			*a = 2;
		}
	}
	for (j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == '*')
		{
			*a = 1;
		}
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == '@')
		{
			*a = 2;
		}
	}
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '*')
	{
		*a = 1;
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '@')
	{
		*a =2;
	}
	if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		*a = 3;
	}
	
}
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
		if (stat == 1)
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
		printf("平局\n");
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
		printf("请选择;");
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