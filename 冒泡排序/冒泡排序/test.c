#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "add.h"

int main()
{

	int sz = 0;
	int arr[] = { 1,2,5,3,7,4 };
	sz = sizeof(arr) / sizeof(arr[0])-1;
	bubble_sort(arr,sz);
	return 0;
}