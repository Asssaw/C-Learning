#include"add.h"


void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");

}
void game()
{
	int row = 0;
	int col = 0;
	int num_bomb = 0;
	int i, j, m, n, k;
	int isdie = 0;
	int isover = 0;
	printf("请输入你想要的行列：");
	scanf("%d %d", &row, &col);
	printf("请输入你想要的雷数：");
	scanf("%d", &num_bomb);
	//char** see = initial_see(row, col);
	char** see = (char**)malloc(sizeof(char*) * row);
	if (see == NULL) {
		fprintf(stderr, "fail!\n");
		return -1;
	}
	for (i = 0; i < row; i++)
	{
		see[i] = (char*)malloc(sizeof(char) * col);
		if (see[i] == NULL) {
			fprintf(stderr, "fail!\n");
			return -1;
		}
		for (j = 0; j < col; j++)
			see[i][j] = '*';
	}
	//char** hide = initial_hide(row, col, num_bomb);
	char** hide = (char**)malloc(sizeof(char*) * (row + 2));
	if (hide == NULL) {
		fprintf(stderr, "fail!\n");
		return -1;
	}
	for (i = 0; i < row + 2; i++)
	{
		hide[i] = (char*)malloc(sizeof(char) * (col + 2));
		if (hide[i] == NULL) {
			fprintf(stderr, "fail!\n");
			return -1;
		}
		for (j = 0; j < col + 2; j++)
			hide[i][j] = ' ';
	}
	for (k = 0; k < num_bomb; k++)
	{
		int pos_col = 0;
		int pos_row = 0;
		int flag = 1;
		do
		{
			pos_col = rand() % (col + 2);
			pos_row = rand() % (row + 2);
			if (pos_col > 0 && pos_col < (col + 1) && pos_row > 0 && pos_row < (row + 1) && hide[pos_row][pos_col] == ' ')
			{
				hide[pos_row][pos_col] = '!';
				flag = 0;
			}
		} while (flag);
	}
	show(see,row,col);
	do
	{
		int row_choose = 0;
		int col_choose = 0;
		int flag = 0;
		printf("请输入你要检查的行列：");
		do
		{
			scanf("%d %d", &row_choose, &col_choose);
			if (see[row_choose][col_choose] != '*' || row_choose < 0 && row_choose > row && col_choose<0 && col_choose > col)
			{
				flag = 1;
				printf("wrong choose,choose again:");
			}
			else
			{
				flag = 0;
			}
		} while (flag);
		
		judge(see,hide,row_choose,col_choose,&isdie,&isover,row,col,num_bomb);
		if (isdie == 1)
		{
			show(see, row, col);
			printf("you die\n");
		}
		if (isover == 1)
		{
			show(see, row, col);
			printf("you win\n");
		}
		if (isdie == 0 && isover == 0)
		{
			show(see, row, col);
		}
	} while ((!isdie)&&(!isover));
	free(see);
	free(hide);

	
		
	
	
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("游戏开始\n");
			game();
			break;
		}
	} while (input);
	return 0;
}