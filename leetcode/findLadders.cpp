//Memory Limit Exceeded
class Solution {
    public:
		vector<vector<string> >findLadders(string& start, string& end, unordered_set<string>& dict)
		{
			vector<vector<string> > ret;
			if(dict.find(start) == dict.end() || dict.find(end) == dict.end())
			  return ret;
			unordered_map<string, int> string2Index;
			vector<string> allString;
			int index = 0;
			for(auto it = dict.begin(); it != dict.end(); ++it)
			{
				string2Index[*it] = index++;
				allString.push_back(*it);
			}
			vector<vector<int>> parent(index, vector<int>());
			vector<bool> visited(index, false);
			queue<int> que;
			que.push(string2Index[start]);
			que.push(-1);
			visited[string2Index[start]] = true;
			parent[string2Index[start]].push_back(-1); 
			bool flag = false;
			while(!que.empty())
			{
				int root = que.front();
				que.pop();
				if(root == -1)
				{
					if(!que.empty())
					{
						que.push(-1);
					}
					continue;
				}
				for(int i = 0; i < allString[root].length(); ++i)
				{
					string childString= allString[root];
					for(char alpha = 'a'; alpha <= 'z'; ++alpha)
					{
						if(childString[i] != alpha)
						{
							childString[i] = alpha;
							int childIndex = string2Index[childString];
							parent[childIndex].push_back(root);
							if(dict.find(childString) != dict.end() && visited[childIndex] == false)
							{
								que.push(childIndex);
								visited[childIndex] = true;
								if(childIndex == string2Index[end])
								{
									flag = true;
								    break;
								}
							}
						}
					}
					if(flag)
					  break;
				}
			    if(flag)
			      break;
			}
			while(!que.empty() && que.front() != -1)
			{
				int root = que.front();
				que.pop();
				for(int i = 0; i < allString[root].length(); ++i)
				{
					string childString= allString[root];
					for(char alpha = 'a'; alpha <= 'z'; ++alpha)
					{
						if(childString[i] != alpha)
						{
							childString[i] = alpha;
							if(dict.find(childString) != dict.end() && string2Index[childString] == string2Index[end])
							{
								parent[string2Index[childString]].push_back(root);
							}
						}
					}
				}
			}
			int cur  = string2Index[end];
			vector<int> path;
			PrintPaths(ret, path, cur, parent, allString);
			return ret;
		}

		void PrintPaths(vector<vector<string> >& ret, vector<int>&path, int index, vector<vector<int> >& parent, vector<string>& allString)
		{
			if(index == -1)
			{
				ret.push_back(vector<string>());
				for(auto it = path.rbegin(); it != path.rend(); ++it)
				{
					ret.back().push_back(allString[*it]);
				}
				return;
			}
			path.push_back(index);
			for(auto it = parent[index].begin(); it != parent[index].end(); ++it)
			{
				PrintPaths(ret, path, *it, parent, allString);
			}
			path.pop_back();
		}

};
