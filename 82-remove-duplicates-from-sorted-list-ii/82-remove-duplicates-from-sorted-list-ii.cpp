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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>v;
        int lst = 12121212;
        unordered_map<int,bool>mp;
        ListNode * L1 , * L2 , * L3 ;
        while(head!=NULL){
            if(head->val!=lst)
                v.push_back(head->val),lst=head->val;
            else mp[lst]=true ;
            head=head->next;
        }
        bool flg = 0 ; 
        for(int i=0;i<v.size();i++){
            if(!mp[v[i]]){
            L1 = new ListNode(v[i]);
            if(!flg) L3 = L1 , L2 = L1 , flg=1;
            else L2->next = L1 , L2 = L2->next;
            }
        }
        return L3;
    }
};