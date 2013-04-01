//打印C(n,m)组合数
//递归的原则是打印以n开头的m个组合数
void PrintCombine(int n, int m, int a[], int k)
{
	if(n < m)
	  return;
	if(m == 1)
	{
		for(int i = n; i >= 1; --i)
		{
			a[k] = i;
			for(int j = k; j >= 0; --j)
			{
				cout<<a[j]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	for(int i = n; i >= m ; --i)
	{
		a[k] = i;
		PrintCombine(i - 1, m - 1, a, k + 1);
	}
}

void Combine(n, m)
{
	int *a = new int[m];
	PrintCombine(n, m, a, 0);
	delete[] a;
}
