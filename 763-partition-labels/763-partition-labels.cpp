class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp,mp1;
        int cou = 0,f=0,S=0;
        vector<int>v;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        for(int i=0;i<s.size();i++){
            S++;
            if(cou==0&&f)
                v.push_back(S-1),S=1,f=0,cout<<s[i];
            if(mp1[s[i]]==0){
                mp1[s[i]]=1;
                cou += mp[s[i]];
                cou--;
                f=1;
            }
            else if(mp1[s[i]]==1)
                cou--;
        }
            if(cou==0&&f)
                v.push_back(S),S=1,f=0;
        return v;
    }
};