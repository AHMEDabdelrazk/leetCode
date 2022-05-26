class Solution {
public:
    int K ;
    vector<int> V;
    set<vector<int>> s;
    void rec(vector<int>vec,unordered_map<int,bool>mp,int I){
        if(vec.size()==K){
            //sort(vec.begin(),vec.end());
            s.insert(vec);
            return ;
        }
        if(vec.size()>K)
            return ;
        for(int i=I;i<V.size();i++){
            unordered_map<int,bool> m = mp;
            vector<int> a = vec;
            if(!m[V[i]] && vec.size()+(V.size()-(i))>=K){
                m[V[i]]=1;
                a.push_back(V[i]);
                rec(a,m,i+1);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        unordered_map<int,bool> M;
        vector<vector<int>> res ; 
        for(int i=1;i<=n;i++) v.push_back(i);
        V = v , K = k;
        rec({},M,0);
        for(auto S:s){
            res.push_back(S);
        }
        return res;
    }
};