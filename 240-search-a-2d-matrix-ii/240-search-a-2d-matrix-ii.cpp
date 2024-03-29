
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=m-1;
        while(s<n && e>=0){
            int element=matrix[s][e];
            if(element==target){
                return true;
            }else if(target>element){
                s++;
            }else{
                e--;
            }
        }
        return false;
    }
};