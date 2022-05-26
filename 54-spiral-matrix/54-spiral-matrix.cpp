class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size() ;
        int i=0,j=0,coun=0;
        vector<int>v;
        int num = n*m;
        while(v.size()<(num)){
            // right
           // cout<<j<<" "<<m;
            while(j<m&&v.size()<(num))
                v.push_back(matrix[i][j++]);
            // down
            i++,j--;
            while(i<n&&v.size()<(num))
                v.push_back(matrix[i++][j]);
            // left
            j--,i--;
            while(j>=coun&&v.size()<(num))
                v.push_back(matrix[i][j--]);
            //up
            n--,m--,j++,i--,coun++;
            while(i>=coun&&v.size()<(num))
                v.push_back(matrix[i--][j]);
            i++,j++;
            //cout<<i<<" "<<j;
        }
        return v;
    }
};