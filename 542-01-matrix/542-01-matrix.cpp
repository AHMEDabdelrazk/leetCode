class Solution {
public:
    
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    bool valid(int r, int c, int R, int C){
        return r >= 0 and c >= 0 and r < R and c < C;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<vector<int>> ans(R, vector<int>(C, INT_MAX));
        
		//push all nodes == 0 for applying multisource:
        queue<pair<int,int>> q;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(mat[r][c] == 0){
                    q.push({r, c});
                    ans[r][c] = 0;
                } 
            }
        }
        
        
        int step = 1;     //track of distance covered from top node of queue
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [r, c] = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int next_r = r + dr[k];
                    int next_c = c + dc[k];
					
					// push into the queue, only if ans gets changed:
                    if(valid(next_r, next_c, R, C)){
                        int oldDist = ans[next_r][next_c];
                        int newDist = step;
                        if(newDist < oldDist){
                            ans[next_r][next_c] = newDist;
                            q.push({next_r, next_c});
                        }
                    }
                }
            }
            
            step++;
        }
        
        return ans;
    }
};