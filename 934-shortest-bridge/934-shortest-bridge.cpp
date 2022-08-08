class Solution {
private:
	void dfs(int i,int j,int row,int col,vector<vector<int>> &grid,vector<pair<int,int>> &p){
		if( i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) return;

		grid[i][j] = 0;
		p.push_back({i,j});

		dfs(i+1,j,row,col,grid,p);
		dfs(i-1,j,row,col,grid,p);
		dfs(i,j+1,row,col,grid,p);
		dfs(i,j-1,row,col,grid,p);

	}
public:
	int shortestBridge(vector<vector<int>>& grid) {

		int row = grid.size();
		if(row == 0) return 0;
		int col = grid[0].size();

		// storing all cordinate of both island
		vector<pair<int,int>> x,y;

		// use flag here because true for 1 island and storing cordinate in x and false for 2nd insland and storing in y 
		bool flag = true;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(grid[i][j] == 1){
					if(flag){
						dfs(i,j,row,col,grid,x);
						flag = false;
					}else dfs(i,j,row,col,grid,y);
				}
			}
		}

		int sz = x.size();
		int sz1 = y.size();

		int ans = INT_MAX;

		// getting minimum distance between x and y  cordinate and that's the answer
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz1; j++){
				int dis = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
				ans = min(ans,dis);
			}
		}

		return ans;

	}
};