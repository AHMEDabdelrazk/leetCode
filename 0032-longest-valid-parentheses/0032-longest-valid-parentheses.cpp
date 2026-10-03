class Solution {
public:
    int longestValidParentheses(string s) {
        int right =0;
        int left = 0;
        int result = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')++right;
            else ++left;
            if(right == left) result = max(result, right * 2);
            else if(left > right) right = 0, left = 0; 
        } 
        right = 0, left = 0; 
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '(')++right;
            else ++left;
            if(right == left) result = max(result, right * 2);
            else if(left < right) right = 0, left = 0; 
        }
        
        return result;
    }
};