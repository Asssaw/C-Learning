#include"add.h"

void calculate(char** see, char** hide, int row_choose, int col_choose,int row, int col )
{
	if ( row_choose >= 0&&row_choose < row && col_choose >= 0 && col_choose < col&&see[row_choose][col_choose] == '*')
	{
		int i, j;
		int sum = 0;
		for (i = row_choose; i <= row_choose + 2; i++)
		{
			for (j = col_choose; j <= col_choose + 2; j++)
			{
				if (hide[i][j] == '!')
				{
					sum += 1;
				}
			}
		}
		//itoa(数字，目标字符串，进制)see[row_choose][col_choose] = sprintf("%d", sum);
		if (sum == 0)
		{
			see[row_choose][col_choose] = sum + '0';

			calculate(see, hide, row_choose - 1, col_choose - 1,row,col);
			calculate(see, hide, row_choose - 1, col_choose, row, col);
			calculate(see, hide, row_choose - 1, col_choose + 1, row, col);
			calculate(see, hide, row_choose, col_choose - 1, row, col);
			calculate(see, hide, row_choose, col_choose + 1, row, col);
			calculate(see, hide, row_choose + 1, col_choose - 1, row, col);
			calculate(see, hide, row_choose + 1, col_choose, row, col);
			calculate(see, hide, row_choose + 1, col_choose + 1, row, col);

		}
		else
		{
			see[row_choose][col_choose] = sum + '0';
		}
	}
	
}
//char** initial_hide(int row, int col,int num)
//{
//	int i, j, m, n, k;
//	char** p = (char**)malloc(sizeof(char*) * (row+2));
//	if (p == NULL) {
//		fprintf(stderr, "fail!\n");
//		return -1;
//	}
//	for (i = 0; i < row+2; i++)
//	{
//		p[i] = (char*)malloc(sizeof(char) * (col+2));
//		if (p[i] == NULL) {
//			fprintf(stderr, "fail!\n");
//			return -1;
//		}
//		for (j = 0; j < col+2; j++)
//			p[i][j] = ' ';
//	}
//	for (k = 0; k < num; k++)
//	{
//		int pos_col = 0;
//		int pos_row = 0;
//		int flag = 1;
//		do
//		{
//			pos_col = rand() % (col+2);
//			pos_row = rand() % (row+2);
//			if (pos_col > 0 && pos_col < (col+1) && pos_row > 0 && pos_row < (row+1) && p[pos_row][pos_col] == ' ')
//			{
//				p[pos_row][pos_col] = '!';
//				flag = 0;
//			}
//		} while (flag);
//	}
//	
//	return p;
//}


void show(char** matrix, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
		
}

void judge(char** see, char** hide, int row_choose, int col_choose, int* isdie,int* isover,int row,int col,int num_bomb)
{
	if (hide[row_choose + 1][col_choose + 1] == '!')
	{
		*isdie = 1;
		see[row_choose][col_choose] = '!';
	}
	else
	{
		calculate(see, hide, row_choose, col_choose, row, col);
		
	}
	int num = 0;
	int m, n;
	for (m = 0; m < row; m++)
	{
		for (n = 0; n < col; n++)
		{
			if (see[m][n] == '*')
			{
				num += 1;
			}
		}
	}
	if (num == num_bomb)
	{
		*isover = 1;
	}

}