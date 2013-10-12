//use a state machine
//http://oj.leetcode.com/problems/valid-number/
class Solution {
private:
    bool f0(const char* s)
    {
        if(isdigit(*s))
          return f1(s + 1);
        else if(*s == '.')
          return f6(s + 1);
        return false;
    }

    bool f1(const char* s)
    {
        if(!*s)
          return true;
        while(*s && isdigit(*s))
          ++s;
        if(!*s)
          return true;
        if(*s == '.')
          return f2(s + 1);
        else if(*s == 'e' || *s == 'E')
          return f3(s + 1);
        else if(*s == ' ')
          return f5(s + 1);
        return false;
    }

    bool f6(const char* s)
    {
        if(isdigit(*s))
          return f7(s + 1);
        return false;
    }

    bool f2(const char* s)
    {
        if(!*s)
          return true;
        if(isdigit(*s))
          return f7(s + 1);
        else if(*s == 'e' || *s == 'E')
          return f3(s + 1);
        else if(*s == ' ')
          return f5(s + 1);
        return false;
    }

    bool f3(const char* s)
    {
        if(isdigit(*s))
          return f4(s + 1);
        else if(*s == '+' || *s == '-')
          return f8(s + 1);
        return false;
    }

    bool f4(const char* s)
    {
        if(!*s)
          return true;
        while(*s && isdigit(*s))
          ++s;
        if(!*s)
          return true;
        if(*s == ' ')
          return f5(s + 1);
        return false;
    }

    bool f5(const char* s)
    {
        if(!*s)
          return true;
        while(*s && *s == ' ')
          ++s;
        if(!*s)
          return true;
        return false;
    }

    bool f7(const char* s)
    {
        if(!*s)
          return true;
        while(*s && isdigit(*s))
          ++s;
        if(!*s)
          return true;
        else if(*s == 'e' || *s == 'E')
          return f3(s + 1);
        else if(*s == ' ')
          return f5(s + 1);
        return false;
    }

    bool f8(const char* s)
    {
        if(*s && isdigit(*s))
          return f7(s + 1);
        return false;
    }

public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        while(*s == ' ')++s;
        if(*s == '+' || *s == '-')
          ++s;
        return f0(s);
    }
};

