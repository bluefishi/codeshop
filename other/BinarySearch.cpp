//这是我参见DFC Tech笔试的一道题目，这道题我思路对了，但代码写错了。
//题目是要在一个排好序的数组int a[]中找到int value应该插入的最前面的位置。
//循环结束后，要么left == right, 要么a[right] < value
//再做一次比较即可
//right = mid - 1; left = mid + 1;保证了数组的收缩性，不会出现无限循环
#include<iostream>
using namespace std;
int BinarySearch(int a[], int left, int right, int value)
{
	int mid = -1;
	while(left < right && a[right] >= value)
	{
		mid = (left + right) / 2;
		if(a[mid] >= value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if(a[right] < value)
		return right + 1;
	else
		return right;
}

int main()
{
	int a[] = {1,2,4,4,4,5,8};
	cout<<BinarySearch(a, 0, sizeof(a) / sizeof(int) - 1, 0)<<endl;
	return 0;
}

