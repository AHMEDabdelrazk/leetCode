class Solution {
public:
    bool isAnagram(string s, string t) {
        bool f=1;
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++)
            mp[t[i]]++;
        for(int i=0;i<s.size();i++)
                mp[s[i]]--;
        for(auto S:mp)
            if(S.second!=0)
                f=0;
        return f;
    }
};