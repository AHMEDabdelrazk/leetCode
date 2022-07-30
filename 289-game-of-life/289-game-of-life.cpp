class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int, int>> arr1;
        vector<pair<int, int>> arr0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int num = board[i][j];
                int c0 = 0;
                int c1 = 0;
                if(i-1>=0 and j-1>=0)
                {
                    if(board[i-1][j-1] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i-1>=0 and j+1<m)
                {
                    if(board[i-1][j+1] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i-1>=0 and j<m)
                {
                    if(board[i-1][j] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i+1<n and j-1>=0)
                {
                    if(board[i+1][j-1] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i+1<n and j<m)
                {
                    if(board[i+1][j] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i+1<n and j+1<m)
                {
                    if(board[i+1][j+1] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i<n and j-1>=0)
                {
                    if(board[i][j-1] == 0)
                        c0++;
                    else
                        c1++;
                }
                if(i<n and j+1<m)
                {
                    if(board[i][j+1] == 0)
                        c0++;
                    else
                        c1++;                  
                }
                if(num == 0)
                {
                    if(c1 == 3)
                    {
                        arr1.push_back({i,j});
                    }
                }
                else
                {
                    if(c1<2 or c1>3)
                    {
                        arr0.push_back({i,j});
                    }
                }
            }
        }
        for(int idx = 0; idx<arr1.size(); idx++)
        {
            int i = arr1[idx].first;
            int j = arr1[idx].second;
            board[i][j] = 1;
        }
        for(int idx=0; idx<arr0.size(); idx++)
        {
            int i = arr0[idx].first;
            int j = arr0[idx].second;
            board[i][j] = 0;
        }
        return;
    }
};