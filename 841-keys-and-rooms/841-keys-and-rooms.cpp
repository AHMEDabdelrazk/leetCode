class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int * visited = new int[n];

        for (int i = 0; i < n ; i++){
            visited[i] = 0;
        }
        DFS(rooms, visited, 0);
        for (int i = 0; i < n; i ++){
            if (visited[i] == 0){
                return false;
            }
        }
        delete[] visited;
        return true;
    }

    void  DFS(vector<vector<int>>& rooms, int* visited, int index){
        visited[index] = 1;
        vector<int> keys = rooms[index];
        for (int i : keys){
            if (visited[i] == 0){
                DFS(rooms, visited, i);
            }
        }
        return;
    }

};