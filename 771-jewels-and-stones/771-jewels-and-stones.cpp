class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int a=0;
        for(int i=0;i<stones.size();i++){
            if(jewels.find(stones[i])!=std::string::npos){
                a++;
            }
        }
        return a;
    }
};