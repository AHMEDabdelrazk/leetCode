class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i=0,j=0,c=0;
        int n=matrix.size();
        vector<int> v;
        unordered_map<int,int>m1,m2;
        for(int x=0;x<n;x++){
            for(int y=n;y>0;y--){
                m1[c]=i;
                m2[c]=j++,c++;
                v.push_back(matrix[y-1][x]);
            }
            i++;
            j=0;
        }
        for(int x=0;x<v.size();x++){
            matrix[m1[x]][m2[x]]=v[x];
        }
    }
};