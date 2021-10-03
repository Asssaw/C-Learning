void bubble_sort(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = 0;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}