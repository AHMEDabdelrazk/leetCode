class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool f1=0;
        for(int i=0;i<matrix.size();i++){
            int col = matrix[i].size()-1;
            if(matrix[i][col]==target){
                f1 = 1 ; break ;
            }
            else if(matrix[i][col]>target){
                for(int j=0;j<=col;j++){
                    if(matrix[i][j]==target)
                        f1=1;
                    else if(matrix[i][j]>target)
                        break;
                }
                break;
            }
        }
        return f1;
    }
};