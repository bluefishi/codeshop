//http://leetcode.com/onlinejudge#question_127
//BSF
//如果构造邻接表的话，复杂度为O(n*n*k)，n为dic的大小，k为word长度
//如果直接构造当前root可能的邻居，即在每个位置上修改一次，这样探测的可能为
//n*k
class Solution {
    public:
		int ladderLength(string& start, string& end, unordered_set<string>& dict)
		{
			if(dict.find(start) == dict.end() || dict.find(end) == dict.end())
			  return 0;
			unordered_map<string, int> string2Index;
			vector<string> allString;
			int index = 0;
			for(auto it = dict.begin(); it != dict.end(); ++it)
			{
				string2Index[*it] = index++;
				allString.push_back(*it);
			}
			vector<int> parent(index, -1);
			vector<bool> visited(index, false);
			queue<int> que;
			que.push(string2Index[start]);
			visited[string2Index[start]] = true;
			parent[string2Index[start]] = -1;
			while(!que.empty())
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
							if(dict.find(childString) != dict.end() && visited[string2Index[childString]] == false)
							{
								int childIndex = string2Index[childString];
								que.push(childIndex);
								parent[childIndex] = root;
								visited[childIndex] = true;
								if(childIndex == string2Index[end])
								  break;
							}
						}
					}
				}
			}
			int cur  = string2Index[end];
			if(parent[cur] == -1)
			  return 0;
			int len = 0;
			while(cur != -1)
			{
				len += 1;
				cur = parent[cur];
			}
			return len;
		}

};
