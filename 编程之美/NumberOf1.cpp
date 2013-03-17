#include<iostream>
using namespace std;

int get(int n)	
{
	if(n <= 0)
		return 0;
	int len = 0;
	int temp = n;
	while(temp)
	{
		temp/=10;
		len +=1;
	}
	int k = 1;
	int cur = 0;
	int sum = 0;
	for(int i = 0; i < len; ++i)
	{
		cur = (n / k) % 10;
		if(cur < 1)
		{
			sum += n / (k * 10) * k;
		}
		else if(cur == 1)
		{
			sum += n / (k * 10) * k;
			sum += n % k;
			sum += 1;
		}
		else
		{
			sum += (n / (k * 10) + 1) * k;
		}
		k *= 10;
	}
	return sum;
}

int main()
{
	int n1, n2;
	while(cin>>n1>>n2)
		cout<<get(n2) - get(n1 - 1)<<endl;
	return 0;
}

