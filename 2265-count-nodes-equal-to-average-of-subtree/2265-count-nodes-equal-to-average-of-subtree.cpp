class Solution {
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr)
            return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int sum = node->val + leftSum + rightSum;
        int count = 1 + leftCount + rightCount;

        if (sum / count == node->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
