class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+1;
         vector<vector<int>>v={{1}};
        vector<int>b{0};
        for(int i=1;i<numRows;i++){
            vector<int> V;
            V.push_back(1);
            for(int j=0;j<b.size()-1;j++)
                V.push_back(b[j]+b[j+1]);
            V.push_back(1);
            v.push_back(V);
            b=V;
        }
        return v[rowIndex];
    }
};