class Solution {
public:
    
    void dfs(int node, int size, vector<vector<int>>& isConnected, vector<int> &vis){
        //as soon as the first node is visited mark it as visited
        vis[node] = 1;
        //now it will traverse the neighbours of each node
        for(int i = 0; i<isConnected[node].size(); i++){
            //if the node is not visited and the two cities are connected 
            if(!vis[i] && isConnected[node][i] == 1){
                dfs(i, size, isConnected, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //size is basically the no. of vertices
        int node = isConnected.size();
        //creating a visited array
        vector<int> vis(node, 0);
        int cnt = 0;
        //hovering over the nodes from 0 till nodes
        for(int i = 0; i<node; i++){
      //if the node is not visited that means its a different component of the same graph
            if(!vis[i]){
                //so increase the count of the components a.k.a provinces and apply dfs
                cnt++;
                dfs(i, node, isConnected, vis);
            }
        }
        return cnt;
    }
};