class Solution {
public:
    int strStr(string haystack, string needle) {
        int I = -1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                string s="";
                for(int j=0; j<needle.size() && j+i<haystack.size();j++) s+=haystack[j+i];
                if(s==needle){
                    I = i;
                    break;
                }
            }
        }
        return I;
    }
};