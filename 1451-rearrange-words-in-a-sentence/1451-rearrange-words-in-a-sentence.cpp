class Solution {
public:
    string arrangeWords(string text) {
        unordered_map<int,int>mp;
        string s="";text+=' ';
        vector<vector<pair<int,string>>> v(100000);
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
              //  cout<<s<<" ";
                mp[s.size()]++;
                v[s.size()].push_back(make_pair(i,s));
                s="";
            }
            else
                s+=tolower(text[i]);
        }
        s="";
        vector<int> M ; 
        for(auto S:mp){M.push_back(S.first);}
        sort(M.begin(),M.end());
        for(auto S:M){
            vector<pair<int,string>> V = v[S];
            sort(V.begin(),V.end());
            for(auto i : V){
                s += i.second + " ";
            }
        }
        s.resize(s.size()-1);
        s[0] = toupper(s[0]);
        return s;
    }
};