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
class BSTIterator {
    stack<TreeNode*> s;
    void populateStack(TreeNode* root){
        if(root==nullptr){
            return;
        }
        s.push(root);
        populateStack(root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        populateStack(root);
    }
    int next() {
        TreeNode* top = s.top();
        s.pop();
        populateStack(top->right);
        return top->val;
    }
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */