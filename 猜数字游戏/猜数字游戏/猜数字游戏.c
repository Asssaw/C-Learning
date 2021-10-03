#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//游戏菜单
void menu()
{
	printf("*************************\n");
	printf("****1.play     2.exit****\n");
	printf("*************************\n");
}
//游戏开始
void game()
{
	int ran = 0;
	int num = 0;
	srand((unsigned int)time(NULL));         
	ran = rand()%100+1;                          
	int flag = 1;
	printf("请写下你猜的数字：");
	do {
		scanf("%d", &num);
		if (num == ran)
			flag = 0;
		else if (num > ran)
			flag = 1;
		else
			flag = 2;
		switch (flag)
		{
		case 0:
			printf("恭喜你猜中了\n");
			break;
		case 1:
			printf("你猜的数字大了，请重新猜：");
			break;
		case 2:
			printf("你猜的数字小了，请重新猜：");
			break;
		default:
			break;
		}
	} while (flag);

	
}
int main()
{
	int a = 0;
	do
	{
		menu();
		printf("请做出你的选择：");
		scanf("%d",&a);
		while (a != 1 && a != 2)
		{
			printf("选择错误，请重新选择：");
			scanf("%d",&a);
		} 
		if (a == 1)
		{
			printf("游戏开始\n");
			game();
		}
		else if (a == 2)
		{
			printf("退出游戏\n");
			break;
		}
		
	} while (a==1);
}