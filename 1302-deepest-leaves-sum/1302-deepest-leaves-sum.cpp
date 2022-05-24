/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> V;
    void rec(int lev , TreeNode * r){
        if(r == NULL)
            return ;
        else {
            V[lev].push_back(r->val);
            rec(lev + 1 , r->left);
            rec(lev + 1 , r->right);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        V.resize(10000);rec(0,root); 
        int res , ans = 0;
        for(int i=0;i<V.size();i++){
            res = 0;
            for(int j=0;j<V[i].size();j++){
                res += V[i][j];
            }
            if(res == 0 ) break;
            ans = res;
        }
        return ans;
    }
};