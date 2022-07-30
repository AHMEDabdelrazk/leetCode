class Node
{
public:
    int val;
    Node *left, *right;
    Node(int k)
    {
        val = k;
    }
};

class SegmentTree
{
    Node *root = nullptr;
    vector<int> v;
    int n;
    Node *makeSegmentTreeUtil(vector<int> &a, int l, int r)
    {
        if (l == r)
            return new Node(a[l]);

        int mid = (l + r) / 2;
        Node *node = new Node(0);
        node->left = makeSegmentTreeUtil(a, l, mid);
        node->right = makeSegmentTreeUtil(a, mid + 1, r);
        node->val = (node->left->val + node->right->val);
        return node;
    }
    int findSumUtil(Node *node, int l, int r, int s, int e)
    {
        if (l > r || !node)
            return -1;
        if ((l >= s && r <= e) || l == r)
        {
            return node->val;
        }
        int mid = (l + r) / 2;
        if (mid >= e)
        {
            return findSumUtil(node->left, l, mid, s, e);
        }
        else if (mid < s)
        {
            return findSumUtil(node->right, mid + 1, r, s, e);
        }
        return (findSumUtil(node->left, l, mid, s, e) + findSumUtil(node->right, mid + 1, r, s, e));
    }
    void updateValueUtil(Node *node, int l, int r, int diff,int idx)
    {
        if (!node || idx < l || idx > r)
            return;
        node->val += diff;
        if (l != r)
        {
            int mid = (l + r) / 2;
            updateValueUtil(node->left, l, mid, diff,idx);
            updateValueUtil(node->right, mid + 1, r, diff,idx);
        }
    }

public:
    SegmentTree(vector<int> &a)
    {
        v = a;
        n = a.size();
        root = makeSegmentTreeUtil(a, 0, n - 1);
    }
    int findSum(int s, int e)
    {
        return findSumUtil(root, 0, n - 1, s, e);
    }
    void updateValue(int idx, int newVal)
    {
        int diff = newVal - v[idx];
        v[idx] = newVal;
        updateValueUtil(root, 0, n - 1, diff,idx);
    }
};

class NumArray {
public:
    SegmentTree *tree = nullptr;
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        tree->updateValue(index,val);
    }
    
    int sumRange(int left, int right) {
        return tree->findSum(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */