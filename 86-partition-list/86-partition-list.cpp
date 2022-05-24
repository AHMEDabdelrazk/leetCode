/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int>v,V;
        ListNode * L1 , * L2 , * L3 = NULL ;
        while(head!=NULL){
            if(head->val>=x) V.push_back(head->val);
            else v.push_back(head->val);
            head = head->next;
        }
        bool flg = 0 ; 
        for(int i=0;i<v.size();i++){
            L1 = new ListNode(v[i]);
            if(!flg) L3 = L1 , L2 = L1 , flg=1;
            else L2->next = L1 , L2 = L2->next;
        }
        for(int i=0;i<V.size();i++){
            L1 = new ListNode(V[i]);
            if(!flg) L3 = L1 , L2 = L1 , flg=1;
            else L2->next = L1 , L2 = L2->next;
        }
        return L3;
    }
};