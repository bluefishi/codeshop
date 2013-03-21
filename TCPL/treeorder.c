/*
 * 打印二叉树的前序，后序，中序遍历
 * 二叉树使用数组的1到n来构造，i节点的左儿子为2*i,右儿子为2*i+1
 * 给定后序和中序可以确定前序，思路为后序中最后一个节点为根，在中序中找到根的位置，其左右划分为左子树和右子树进行递归
*/
#include<iostream>
using namespace std;

void PrintFormer(int a[], int nid, int nodeNum, int **b) 
{
	if(nid > nodeNum)
		return;
	cout<<a[nid]<<" ";
	**b = a[nid];
	*b += 1;
	PrintFormer(a, nid * 2, nodeNum, b);
	PrintFormer(a, nid * 2 + 1, nodeNum, b);
}

void PrintMiddle(int a[], int nid, int nodeNum, int **b)
{
	if(nid > nodeNum)
		return;
	PrintMiddle(a, nid * 2, nodeNum, b);
	cout<<a[nid]<<" ";
	**b = a[nid];
	*b += 1;
	PrintMiddle(a, nid * 2 + 1, nodeNum, b);
}

void PrintLatter(int a[], int nid, int nodeNum, int **b)
{
	if(nid > nodeNum)
		return;
	PrintLatter(a, nid * 2, nodeNum, b);
	PrintLatter(a, nid * 2 + 1, nodeNum, b);
	cout<<a[nid]<<" ";
	**b = a[nid];
	*b += 1;
}

int FindIndex(int data[], int l, int r, int k)
{
	for(int i = l; i <= r; ++i)
		if(data[i] == k)
			return i;
	return -1;
}
void PrintFormerGiveMiddleAndLatter(int middle[], int latter[], int count)
{
	if(count <= 0)
		return;
	int root = latter[count - 1];
	cout<<root<<" ";
	int rootMiddleIndex = 0;
	for(int i = 0; i < count; ++i)
		if(middle[i] == root)
			rootMiddleIndex = i;
	PrintFormerGiveMiddleAndLatter(middle, latter, rootMiddleIndex);
	PrintFormerGiveMiddleAndLatter(middle + rootMiddleIndex + 1, latter + rootMiddleIndex, count - rootMiddleIndex - 1); 
}
int main()
{
	const int max = 15;
	int tree[max + 1];
	int formerOrder[max + 1];
	int middleOrder[max + 1];
	int latterOrder[max + 1];
	int *p;
	for(int i = 1; i <= max; ++i)
		tree[i] = i;
	p = formerOrder;
	PrintFormer(tree, 1, max, &p); 
	cout<<endl;

	p = middleOrder;
	PrintMiddle(tree, 1, max, &p);
	cout<<endl;

	p = latterOrder;
	PrintLatter(tree, 1, max, &p);
	cout<<endl;

	int res[max + 1];
	for(int i = 0; i <= max; ++i)
		res[i] = 0;
	PrintFormerGiveMiddleAndLatter(middleOrder, latterOrder, max);
	cout<<endl;
	return 0;
}


