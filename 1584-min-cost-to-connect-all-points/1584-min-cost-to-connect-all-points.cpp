class Solution {
public:
    /*
    Pretty standard variation of Kruskal Algorithm. Similar to https://leetcode.com/problems/optimize-water-distribution-in-a-village/
    
    Algorithm : 
        1. construct a graph containing all the edges with it's nodes and it's weight
        2. Sort the edges vector based on the weights
        3. Apply Kruskal to find the MST(Using DSU data structure)
            a. Initialize parent vector of n nodes of same values as it's index
            b. For each edge in the edges vector, find the parent of both it's nodes, 
                i. if they are equal it means this edge need not be included in the MST.
                ii. if they are unequal it means that edge has to be included in the MST. 
                    Make one node as parent of another.
            c. When their parents were unequal add the edge's weight value in the result as this is part of the MST.
    */
    struct edge {
        int u;
        int v;
        int wt;
    };
    int n;
    vector<int> parent;
    vector<edge> edges;
    
    int getParent(int index) {
        if (parent[index] == index) return index;
        return parent[index] = getParent(parent[index]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, w});
                edges.push_back({j, i, w});
            }
        }
        parent = vector<int> (n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        auto lmd = [&](auto& a, auto& b) {
            return a.wt < b.wt;
        };
        sort(edges.begin(), edges.end(), lmd);
        
        int res = 0;
        for (auto& edge : edges) {
            int p1 = getParent(edge.u);
            int p2 = getParent(edge.v);
            
            // This means this edge's nodes have been already part of the MST without it's edges value. 
            // So igonre it's weight.
            if (p1 == p2) {
                continue;
            } 
            // If they are unequal, make one's parent as the parent of another's parent.
            else if (p1 > p2) {
                parent[p1] = p2;
            }
            else {
                parent[p2] = p1;
            }
            // Add curr weight to the res
            res += edge.wt;
        }
        return res;
    }
};