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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode *h , *N;
        for(int i=0;i<v.size();i++){
            ListNode *H = new ListNode(v[i]);
            if(i==0){ h = H ; N = H;}
            else{ N->next = H; N = N->next;}
        }
        return h;
    }
};