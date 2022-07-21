class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        
        while (columnNumber>0){
            
            char curr = (columnNumber-1)%26 + 'A';
            ans = curr + ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
    }
};