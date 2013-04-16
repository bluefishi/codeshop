#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
using namespace std;

int n = 7;
int visited[20];
int parent[20];
int e[7][7] = {
                    {0,1,1,0,0,0,0},
                    {0,0,0,1,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,1,0,0},
                    {0,1,1,0,0,0,0},
                    {0,1,0,0,1,0,1},
                    {1,0,1,0,1,1,0}};
void PrintPath(int i, int start)
{
	if(i == start || i == -1)
	{
		cout<<i<<" ";
		return;
	}
	PrintPath(parent[i], start);
	cout<<i<<" ";
}


void DFS(int v, int start){
	visited[v] = 1;
	int t = -1;
	for(int i = 0; i < n; ++i){
		if(e[v][i] == 1){
			if(visited[i] == 1)
			{
				if(i == start){
					t = v;
					while(t != -1 && t != i && t >= start){
						t = parent[t];
					}
					if(t == start){
						//report a path
						PrintPath(v, i);
						cout<<i<<endl;
					}
				}
			}
			else{
				parent[i] = v;
				DFS(i, start);
			}
		}
	}
	visited[v] = 0;
}

void PrintCycle()
{
	for(int i = 0; i < n; ++i)
			DFS(i, i);
}
int main()
{
	for(int i = 0; i < n; ++i)
		visited[i] = 0;
	parent[0] = -1;
	PrintCycle();
	return 0;
}

