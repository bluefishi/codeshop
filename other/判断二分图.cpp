//思路：通过BFS染色0, 1，父亲与孩子染不同的颜色，如果遇到一个和自己染色
//相同的儿子则表示有奇回路
bool BFSInternal(int root, vector<vector<int> >& adjacentList, vector<int>& visited);
bool BFS(vector<vector<int> >& adjacentList, int nodeNumber)
{
	vector<int> visited(nodeNumber, -1);
	for(int i = 0; i < nodeNumber; ++i)
	{
		if(visited[i] == -1)
		{
			if(BFSInternal(i, adjacentList, visited) == false)
				return false;
		}
	}
	return true;
}

bool BFSInternal(int root, vector<vector<int> >& adjacentList, vector<int>& visited)
{
	visited[root] = 0;
	queue<int> que;
	que.push(root);
	while(!que.empty())
	{
		int parent = que.front();
		que.pop();
		for(int i = 0; i < adjacentList[parent].size(); ++i)
		{
			if(visited[adjacentList[parent][i]] == -1)
			{
				visited[adjacentList[parent][i]] = 1 - visited[parent];
				que.push(adjacentList[parent][i]);
			}	
			else if(visited[adjacentList[parent][i]] == visited[parent])
				return false;
		}
	}
	return true;
}

