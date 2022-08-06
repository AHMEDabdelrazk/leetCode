class Solution {
public:
    int lengthOfLastWord(string s) {
        bool f=0;
        int r=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ' && f )
                break;
            if(s[i]!=' ')
                r++,f=1;
        }
        return r;
    }
};