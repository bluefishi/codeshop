//http://oj.leetcode.com/problems/text-justification/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ret;
        int start = 0;
        int end = 0;
        while(end < words.size())
        {
            int lineLen = 0;
            int emptyWordNum = 0;
            while(end < words.size() && lineLen + words[end].length() <= L)
            {
				if(words[end].length() != 0)
                    lineLen += words[end].length() + 1;
				else
					emptyWordNum += 1;
                ++end;
            }
            int wordNumber = end - start;
            int realWordNumber = wordNumber - emptyWordNum;
			if(realWordNumber == 1 || realWordNumber == 0 || end == words.size())
            {
                int spaceRight = L;
                ret.push_back("");
                while(start < end - 1)
                {
					if(words[start].length() != 0)
					{
						ret.back() += words[start];
						ret.back() += " ";
						spaceRight -= (words[start].length() + 1);
					}
					++start;
                }
                ret.back() += words[start];
				spaceRight -= words[start].length();
                ret.back() += string(spaceRight, ' ');
            }
            else
            {
                ret.push_back("");
                int totalSpaceNumber = L - lineLen + realWordNumber;
				int moreSpaceUpper = totalSpaceNumber % (realWordNumber - 1);
                int i = 0;
                while(i < moreSpaceUpper)
                {
					if(words[start].length() != 0)
					{
						ret.back() += words[start];
						ret.back() += string(totalSpaceNumber / (realWordNumber - 1) + 1, ' ');
                        ++i;
					}
                    ++start;
                }
				while(i < realWordNumber - 1)
                {
					if(words[start].length() != 0)
					{
						ret.back() += words[start];
						ret.back() += string(totalSpaceNumber / (realWordNumber - 1), ' ');
                        ++i;
					}
                    ++start;
                }
                ret.back() += words[start];
                ++start;
            }
            start = end;
        }
        return ret;
    }
};

