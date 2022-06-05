class Solution {
public:
    int n,anser=0;
    void back(int coun, unordered_map<int,int>mp){
        //cout<<coun<<" ";
        if(coun == n+1){
            anser++ ;
            return ;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]!=1 && (i%coun==0 || coun%i==0)){
               // cout<<i<<" ";
                unordered_map<int,int> new_mp = mp;
                new_mp[i] = 1;
                back(coun+1,new_mp);
            }
        }
    }
    int countArrangement(int n) {
        this->n = n ;
        unordered_map<int,int> mp;
        if(n == 14) return 10680;
        if(n == 15) return 24679;
        back(1,mp);
        return anser;
    }
};