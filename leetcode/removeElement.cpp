//http://leetcode.com/onlinejudge#question_27
class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> start;
            vector<int> stop;
            for(int i = 0; i < n;)
            {
                if(A[i] == elem)
                {
                    start.push_back(i);
                    while(i < n && A[i] == elem)
                      ++i;
                    stop.push_back(i);
                }
                else
                {
                    ++i;
                }
            }
            start.push_back(n);
            int index = start[0];
            for(int i = 0; i < stop.size(); ++i)
            {
                for(int j = stop[i]; j < n && j < start[i + 1]; ++j, ++index)
                {
                    A[index] = A[j];
                }
            }
            return index;
        }
};

