//http://oj.leetcode.com/problems/minimum-window-substring/
//用两个指针扫描S
//end扫到start->end之间覆盖T
//然后start开始往后扫，直到无法覆盖T，不断更新最小的覆盖长度
//重复end扫描
class Solution {
    public:
        string minWindow(string S, string T) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            unordered_map<char, int> tcount;
            unordered_map<char, int> ccount;
            for(int i = 0; i < T.size(); ++i)
            {
                ccount[T[i]] = 0;
                if(tcount.find(T[i]) != tcount.end())
                  tcount[T[i]] += 1;
                else
                  tcount[T[i]] = 1;
            }
            int end = 0;
            int start = 0;
            int count = 0;
            int optStart = -1;
            int optLen = S.length() + 1;
            for(end = 0; end < S.size(); ++end)
            {
                if(tcount.find(S[end]) != tcount.end())
                {
                    ccount[S[end]] += 1;
                    if(ccount[S[end]] == tcount[S[end]])
                      count += 1;
                    while(count == tcount.size())
                    {
                        if(tcount.find(S[start]) != tcount.end())
                        {
                            if(end - start + 1< optLen)
                            {
                                optLen = end - start + 1;
                                optStart = start;
                            }
                            ccount[S[start]] -= 1;
                            if(ccount[S[start]] < tcount[S[start]])
                              count -= 1;
                        }
                        ++start;
                    }
                }
            }
            if(optLen <= S.length())
            {
                return S.substr(optStart, optLen);
            }
            return "";
        }
};


