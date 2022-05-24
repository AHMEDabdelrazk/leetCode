/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* N=root , *res=root;
        queue<Node*>Q,q;
       if(root!=NULL) Q.push(root) , q.push(root);
        while(!q.empty()){
            while(!Q.empty()){
                if(Q==q) q = {};
                Node * n =Q.front();
                Q.pop();
                if(n->left!=NULL) q.push(n->left);
                if(n->right!=NULL) q.push(n->right);
                
                if(!Q.empty())n->next = Q.front();
                else n->next = NULL;
            }
            Q=q;
        }
        return N;
    }
};