class Solution {
public:
    bool wordPattern(string patt, string str) 
    {
        vector<int> patt_map(26,0);
        unordered_map<string,int> str_map;
        istringstream  is(str);
        string s;
        int n=patt.size(),i=0;
        while(is>>s)
        {
            if(i==n||patt_map[patt[i]-'a']!=str_map[s])
            {
                return false;
            }
            else
            {
                patt_map[patt[i]-'a']=str_map[s]=i+1;
            }
            i++;
        }
        return i==n;
        
    }
};