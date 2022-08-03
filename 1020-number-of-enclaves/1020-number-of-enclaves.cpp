class Solution {
public:
    bool canWeCrossBoundery(vector<vector<int>> &grid, int i, int j, int &numberOfLandCells){
        if(i<0 || j<0 || i==grid.size() || j== grid[0].size()){
            return true;
        }
        if(grid[i][j]!=1){
            return false;
        }
        grid[i][j]=2;
        numberOfLandCells++;
        bool leftMove = canWeCrossBoundery(grid, i, j-1, numberOfLandCells);
        bool rightMove = canWeCrossBoundery(grid, i, j+1, numberOfLandCells);
        bool upMove = canWeCrossBoundery(grid, i-1, j, numberOfLandCells);
        bool downMove = canWeCrossBoundery(grid, i+1, j, numberOfLandCells);
        
        return leftMove || rightMove || upMove || downMove;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count =0, n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int numberOfLandCells = 0;
                if(!canWeCrossBoundery(grid, i, j, numberOfLandCells))
                    count += numberOfLandCells;
            }
        }
        return count;
    }
};