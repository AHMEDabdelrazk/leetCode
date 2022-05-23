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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int res=0;
        ListNode* l3 ;ListNode **p = &l3;
        while(l2!=NULL||l1!=NULL)
        {
            if(l1!=NULL){res+=l1->val; l1=l1->next;}
            if(l2!=NULL){res+=l2->val; l2=l2->next;}
            (*p)=new ListNode(res%10);
            res/=10;
            p=&(*p)->next;
        }
            
        if(res !=0){(*p)=new ListNode(res);
        p=&(*p)->next;} 
        return l3;        
    }
};