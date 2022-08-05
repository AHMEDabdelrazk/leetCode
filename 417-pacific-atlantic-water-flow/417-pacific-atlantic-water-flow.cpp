

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int i, int j, vector<vector<bool>>& visited, int prevHeight){
        
        visited[i][j] = true;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        for (int k=0; k<4; k++){
            int X = i + dx[k];
            int Y = j + dy[k];
            
            if(X >= 0 && X < row && Y >= 0 && Y<col && heights[X][Y]>=prevHeight && !visited[X][Y]){
                
                dfs(heights, row, col, X, Y, visited, heights[X][Y]);
            }       
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> pac_visited(row, vector<bool>(col, false));
        vector<vector<bool>> atl_visited(row, vector<bool>(col, false));
        
        vector<vector<int>> result;
        
        for(int c=0; c<col; c++){
            dfs(heights, row, col, 0, c, pac_visited, heights[0][c]);
            dfs(heights, row, col, row-1, c, atl_visited, heights[row-1][c]);
        }
        
        
        for(int r=0; r< row; r++){
            dfs(heights, row, col, r, 0, pac_visited, heights[r][0]);
            dfs(heights, row, col, r, col-1, atl_visited, heights[r][col-1]);
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(pac_visited[i][j] && atl_visited[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};