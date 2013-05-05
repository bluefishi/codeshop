//http://leetcode.com/onlinejudge#question_1
//这个虽然pass了，但是依然调用了排序算法sort，时间复杂度为O(nlogn)
//排序之后，使用两个索引i和j，i初始化为数组头，j初始化为数组尾
//如果v[i] + v[j] > target --j
//如果v[i] + v[j] < target ++i
//else return (i, j)
//第二个solution使用了map来做，思路也比较直接
//如果数组是排序好的话，可以使用第一个方法
class Node
{
public:
    int v;
	int i;
};
bool compare1(const Node& a, const Node& b)
{
	return a.v < b.v;
}
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Node> temp(numbers.size());
		for(int i = 0; i < numbers.size(); ++i)
		{
			temp[i].i = i;
			temp[i].v = numbers[i];
		}
		sort(temp.begin(), temp.end(), compare1);
		static vector<int> res(2);
		int i = 0;
		int j = temp.size() - 1;
		for(; i < j;)
		{
			if(temp[i].v + temp[j].v > target)
			{
				--j;
			}
			else if(temp[i].v + temp[j].v < target)
			{
				++i;
			}
			else
			{
				res[0] = min(temp[i].i, temp[j].i) + 1;
				res[1] = max(temp[i].i, temp[j].i) + 1; 
				return res;
			}
		}
		res[0] = -1;
		res[1] = -1;
		return res;
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
		static vector<int> res(2);
		map<int, int> m;
		for(int i = 0; i < numbers.size(); ++i)
		{
			if(m.find(numbers[i]) == m.end())
				m[target - numbers[i]] = i;
			else
			{
				res[0] = m[numbers[i]] + 1;
				res[1] = i + 1;
				return res;
			}
		}
	}
};

