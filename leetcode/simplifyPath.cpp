//http://oj.leetcode.com/problems/simplify-path/
//这种状态转移的东西，一直不知道怎么搞
class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        char* ret = new char[path.length() + 1];
        int index = -1;
        int i = 0;
        while(i < path.length())
        {
            if(path[i] == '/')
            {
                if(index < 0)
                  ret[++index] = '/';
                else if(ret[index] != '/')
                  ret[++index] = '/';
                ++i;
            }
            else if(path[i] == '.')
            {
                if(i < path.length() - 1)
                {
                    if(path[i+1] == '.')
                    {
                        while(index >= 0 && ret[index] != '/')
                          --index;
                        --index;
                        while(index >= 0 && ret[index] != '/')
                          --index;
                        i += 2;
                    }
                    else if(path[i+1] != '/')
                    {
                        ret[++index] = path[i];
                        ++i;
                    }
                    else
                      ++i;
                }
                else
                  ++i;
            }
            else
            {
                ret[++index] = path[i++];
            }
        }
        if(index < 0)
        {
            delete[] ret;
            return "/";
        }
        while(index >= 1 && ret[index] == '/')
          --index;
        ret[++index] = 0;
        string str = ret;
        delete[] ret;
        return str;
    }
};
