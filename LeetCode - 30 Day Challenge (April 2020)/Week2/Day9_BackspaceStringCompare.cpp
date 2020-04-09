class Solution {
public:
    void getFinalString(string &str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '#')
            {
                str.erase(i, 1);
                if(i > 0)
                {
                    str.erase((i-1), 1);
                    i = i - 2;
                }
                else
                   i = i - 1;   
            }
        }
    }
    
    bool backspaceCompare(string S, string T) {
        getFinalString(S);
        getFinalString(T);
        
        if(S.compare(T) == 0)
            return true;
        else
            return false;
    }
};
