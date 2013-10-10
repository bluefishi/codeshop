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
            while(end < words.size() && lineLen + words[end].length() < L)
            {
                lineLen += words[end].length() + 1;
                ++end;
            }
            int wordNumber = end - start;
            if(wordNumber == 1)
            {
                ret.push_back(words[start] + string(L - words[start].length(), ' '));
            }
            else
            {
                ret.push_back("");
                int totalSpaceNumber = L - lineLen + wordNumber;
                int moreSpaceUpper = totalSpaceNumber % (wordNumber - 1);
                int i = 0;
                for(;i < moreSpaceUpper; ++i)
                {
                    ret.back() += words[start];
                    ret.back() += string(totalSpaceNumber / (wordNumber - 1) + 1, ' ');
                    ++start;
                }
                for(; i < wordNumber - 1; ++i)
                {
                    ret.back() += words[start];
                    ret.back() += string(totalSpaceNumber / (wordNumber - 1), ' ');
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

