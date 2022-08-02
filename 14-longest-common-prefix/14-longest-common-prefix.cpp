class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int col = 200 + 1;
        string res = "" , che = "" ;
        for(int i=0;i<strs.size();i++){
            if(col > strs[i].size()){
                col = strs[i].size();
                che = strs[i];
            }
        }
        for(int i=0;i<strs.size();i++){
            string ch = "";
            for(int j=0;j<che.size();j++){
                if(strs[i][j]==che[j])
                    ch+=che[j];
                else 
                    break;
            }
            che = ch;
        }
        return che;
    }
};