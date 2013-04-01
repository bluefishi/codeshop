void PrintPermutation(int a[], int n, int total)
{
	static int count = 1;
	if(n < 0)
		return;
	if(n == 1)
	{
		cout<<count++<<":";
		for(int i = 0; i < total; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < n; ++i)
	{
		swap(a[i], a[n - 1]);
		PrintPermutation(a, n - 1, total);
		swap(a[i], a[n - 1]);
	}
}

void Permutation(int n)
{
	int *a = new int[n];
	for(int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}
	PrintPermutation(a, n, n);
	delete[] a;
}

