void swapElements(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quickSort(int* mas, int size)
{
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];

	do
	{
		while (mas[i] < mid)
		{
			i++;
		}
		while (mas[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			swapElements(&mas[i], &mas[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		quickSort(mas, j + 1);
	}
	if (i < size)
	{
		quickSort(&mas[i], size - i);
	}
}