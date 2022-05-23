class Solution {
public:
    int longestValidParentheses(string s) {
      
        
        int open =0, close =0;
        int maxLength = 0;
         
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                int len = open + close;
                maxLength = max(maxLength, len);
            }
            else if(close > open)
            {
                open = close = 0;
            }
        }
        
        open = close = 0;
        
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                int len = open + close;
                maxLength = max(maxLength, len);
            }
            else if(open > close)
            {
                open = close = 0;
            }
        }
        
        return maxLength;
    }
};