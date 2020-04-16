// Solution 1
class Solution {
public:
    bool checkValidString(string s) {
        int leftParen = 0;
        int rightParen = 0;
        
        if(s.length() == 1 && s != "*")
            return false;
        
        for(char &ch : s)
        {
            if(ch == '(' || ch == '*')
                leftParen++;
            else
                leftParen--;
            
            if(leftParen < 0)
                return false;
        }
        
        for(int i = s.length() - 1; i > 0; i--)
        {
            if(s[i] == ')' || s[i] == '*')
                rightParen++;
            else
                rightParen--;
            
            if(rightParen < 0)
                return false;
        }
        
        return true;
    }
};

// Solution 2

class Solution {
public:
  bool checkValidString(string s)   {
      int lo = 0, hi = 0;
      
      for(char &ch : s)
      {
          if(ch == '(')
              lo++;
          else
              lo--;
          
          if(ch != ')')
              hi++;
          else
              hi--;
          
          if(hi < 0)
              break;
          
          lo = max(lo, 0);
      }
      
      return lo == 0;
  }
};

