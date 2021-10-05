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
	int flag = 1;
	do {
		scanf("%d %d", &a, &b);
		if (board[a][b] == ' ' && a < 3 && b < 3)
		{
			board[a][b] = '*';
			flag = 0;
		}

		else
		{
			printf("Ñ¡Ôñ´íÎó£¬ÖØÑ¡£º");
		}
	} while (flag);
	

}
void computer(char board[][COL])
{
	int flag = 1;
	int win1 = 0;
	int win2 = 0;
	int win3 = 0;
	int ctn1 = 0;
	int ctn2 = 0;
	int ctn3 = 0;
	int canwin = 0;
	int randpos = 1;
	int j = 0;
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (((board[i][0] == '@' && board[i][1] == '@') || (board[i][0] == '@' && board[i][2] == '@') || (board[i][2] == '@' && board[i][1] == '@') )&&board[i][0] != '*' && board[i][1] != '*' && board[i][2] != '*')
		{
			board[i][0] = '@';
			board[i][1] = '@';
			board[i][2] = '@';
			win3 = 1;
			win2 = 1;
			win1 = 1;
			canwin = 1;
			randpos = 0;
			break;
		}

	}
	if (win3 == 0)
	{
		for (j = 0; j < COL; j++)
		{

			if (((board[0][j]=='@'&&board[1][j]=='@')||( board[0][j] == '@' && board[2][j] == '@')||( board[2][j] == '@' && board[1][j] == '@')) && board[0][j] != '*' && board[1][j] != '*' && board[2][j] != '*')
			{
				board[0][j] = '@';
				board[1][j] = '@';
				board[2][j] = '@';
				win2 = 1;
				win1 = 1;
				canwin = 1;
				randpos = 0;
				break;
			}
		}
	}
	if (win2 == 0)
	{
		if (((board[0][0] == board[1][1] || board[0][0] == board[2][2] || board[1][1] == board[2][2]) && (board[0][0] == '@' || board[1][1] == '@' || board[2][2] == '@')) && board[0][0] != '*' && board[1][1] != '*' && board[2][2] != '*')
		{
			board[0][0] = '@';
			board[1][1] = '@';
			board[2][2] = '@';
			win1 = 1;
			canwin = 1;
			randpos = 0;
		}
	}
	if (win1 == 0)
	{
		if (((board[2][0] == board[1][1] || board[2][0] == board[0][2] || board[1][1] == board[0][2]) && (board[2][0] == '@' || board[1][1] == '@' || board[0][2] == '@') )&& board[2][0] != '*' && board[1][1] != '*' && board[0][2] != '*')
		{
			board[2][0] = '@';
			board[1][1] = '@';
			board[0][2] = '@';
			canwin = 1;
			randpos = 0;
		}
	}
	if (canwin == 0)
	{
		for (i = 0; i < ROW; i++)
		{
			if (((board[i][0] == '*' && board[i][1] == '*') || (board[i][0] == '*' && board[i][2] == '*') || (board[i][2] == '*' && board[i][1] == '*') )&& board[i][0] != '@' && board[i][1] != '@' && board[i][2] != '@')
			{
				for (j = 0; j < COL; j++)
				{
					if (board[i][j] == ' ')
					{
						board[i][j] = '@';
					}
				}
				ctn3 = 1;
				ctn2 = 1;
				ctn1 = 1;
				randpos = 0;
				break;
			}

		}
		if (ctn3 == 0)
		{
			for (j = 0; j< COL; j++)
			{

				if (((board[0][j] == '*' && board[1][j] == '*') || (board[0][j] == '*' && board[2][j] == '*') || (board[2][j] == '*' && board[1][j] == '*')) && board[0][j] != '@' && board[1][j] != '@' && board[2][j] != '@')
				{
					for (i = 0; i < COL; i++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = '@';
						}
					}
					ctn2 = 1;
					ctn1 = 1;
					randpos = 0;
					break;
				}
			}
		}
		if (ctn2 == 0)
		{
			if (((board[0][0] == '*' && board[1][1] == '*') || (board[0][0] == '*' && board[2][2] == '*') || (board[2][2] == '*' && board[1][1] == '*') )&& board[0][0] != '@' && board[1][1] != '@' && board[2][2] != '@')
			{
				if (board[0][0] == ' ')
				{
					board[0][0] = '@';
				}
				if (board[1][1] == ' ')
				{
					board[1][1] = '@';
				}
				if (board[2][2] == ' ')
				{
					board[2][2] = '@';
				}
				ctn1 = 1;
				randpos = 0;
			}
		}
		if (ctn1 == 0)
		{
			if (((board[0][2] == '*' && board[1][1] == '*') || (board[0][2] == '*' && board[2][0] == '*') || (board[2][0] == '*' && board[1][1] == '*') )&& board[0][2] != '@' && board[1][1] != '@' && board[2][0] != '@')
			{
				if (board[0][2] == ' ')
				{
					board[0][2] = '@';
				}
				if (board[1][1] == ' ')
				{
					board[1][1] = '@';
				}
				if (board[2][0] == ' ')
				{
					board[2][0] = '@';
				}
				randpos = 0;
			}
		}
	}
	
	if (randpos == 1)
	{
		do
		{
			int col = 0;
			int row = 0;
			//srand((unsigned int)time(NULL));
			row = rand() % 3;
			//srand((unsigned int)time(NULL));
			col = rand() % 3;
			if (board[row][col] == ' ')
			{
				board[row][col] = '@';
				flag = 0;
			}
		} while (flag);
	}
	
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
void exam(char board[][COL], int* a)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '*')
		{
			*a = 1;
			break;
		}
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '@')
		{
			*a = 2;
			break;
		}
	}
	for (j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == '*')
		{
			*a = 1;
			break;
		}
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == '@')
		{
			*a = 2;
			break;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '*')
	{
		*a = 1;
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == '*')
	{
		*a = 1;
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '@')
	{
		*a = 2;
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == '@')
	{
		*a = 2;
	}
	if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		*a = 3;
	}
}