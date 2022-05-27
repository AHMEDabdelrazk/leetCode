class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m; set<int> s;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            s.insert(nums[i]);
        }
        int rc=0, c;
        for(auto i: s){
            if(m[i+1]){
                c=m[i] + m[i+1];
                if(c> rc) rc= c;
            }
        }
        return rc;
        
    }
};