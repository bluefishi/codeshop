//http://ac.jobdu.com/problem.php?cid=1039&pid=0
//二位矩阵，行，列有序
//给定一个输入，判断是否存在
//On算法正确，但是只能用scanf输入
//Olog算法错误，还没找出来错误原因
#include<iostream>
#include<fstream>
#include<string>
//#include<Windows.h>
using namespace std;

int a[1000][1000];
int m, n;
bool On(int candidate)
{
	int i = 0;
	int	j = n - 1;
	while(i < m && j >= 0)
	{
		if(candidate > a[i][j])
			i += 1;
		else if(candidate < a[i][j])
			j -= 1;
		else
		{
			return true;
		}
	}
	return false;
}

bool OLog(int candidate, int l, int r, int t, int b)
{
	int im, jm;
	if(l <= r && t <= b && l >= 0 && r < n && t >=0 && b < m)
	{
		if(l == r && t == b)
			if(a[l][t] == candidate)
				return true;
			else
				return false;
		jm = (l + r) / 2;
		im = (t + b) / 2;
		if(a[im][jm] == candidate)
			return true;
		else if(candidate < a[im][jm])
			return OLog(candidate, l, jm - 1, t, im - 1) || OLog(candidate, jm, r, t, im - 1) || OLog(candidate, l,  jm - 1, im, b); 
		else
			return OLog(candidate, jm + 1, r, t, im - 1) || OLog(candidate, l, jm, im + 1, b) || OLog(candidate, jm + 1, r, im, b);
	}
	else
		return false;
}

void CreateTest()
{
	ofstream fp("a.txt");
	fp<<1000<<" "<<1000<<endl<<-1<<endl;
	int k = 1;
	for(int i = 0; i < 1000; ++i)
	{
		for(int  j = 0; j < 1000; ++j)
			fp<<k++<<" ";
		fp<<endl;
	}
	fp.close();
}
int main()
{
	//CreateTest();
	m = n = 0;
	int candidate;
	int i, j;
	//int ts = GetTickCount();
	while(scanf("%d %d",&m, &n) != EOF)
	{
		scanf("%d", &candidate);
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		//if(OLog(candidate, 0, n - 1, 0, m - 1) == true)
		if(On(candidate) == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	//cout<<GetTickCount() - ts<<endl;
	return 0;
}

