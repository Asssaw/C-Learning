#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//��Ϸ�˵�
void menu()
{
	printf("*************************\n");
	printf("****1.play     2.exit****\n");
	printf("*************************\n");
}
//��Ϸ��ʼ
void game()
{
	int ran = 0;
	int num = 0;
	srand((unsigned int)time(NULL));         
	ran = rand()%100+1;                          
	int flag = 1;
	printf("��д����µ����֣�");
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
			printf("��ϲ�������\n");
			break;
		case 1:
			printf("��µ����ִ��ˣ������²£�");
			break;
		case 2:
			printf("��µ�����С�ˣ������²£�");
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
		printf("���������ѡ��");
		scanf("%d",&a);
		while (a != 1 && a != 2)
		{
			printf("ѡ�����������ѡ��");
			scanf("%d",&a);
		} 
		if (a == 1)
		{
			printf("��Ϸ��ʼ\n");
			game();
		}
		else if (a == 2)
		{
			printf("�˳���Ϸ\n");
			break;
		}
		
	} while (a==1);
}