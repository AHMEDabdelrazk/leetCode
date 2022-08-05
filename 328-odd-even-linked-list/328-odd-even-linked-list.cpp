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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode*optr=head;
        ListNode*eptr=head->next;
        ListNode*epstart=eptr;
        
        while(optr->next!=NULL && eptr->next!=NULL){
            optr->next=eptr->next;
            eptr->next=optr->next->next;
            
            optr=optr->next;
            eptr=eptr->next;
            
        }
        optr->next=epstart;
        
      return head;
    }
};