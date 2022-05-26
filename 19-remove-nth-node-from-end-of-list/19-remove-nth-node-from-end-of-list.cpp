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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *L1=head,*L2=head,*L3=head,*L4=head;
        int N = 0 , C = 1 ;
        while(L1!=NULL) {N++;L1=L1->next;}
        n = (N)-n ;
        if(n==0)C=0;
        cout<<n<<" "<<N<<" "; 
        while(L2!=NULL){
            cout<<C<<" ";
            if(C==n && C==N-1){
                L2->next = NULL;
                break;}
            else if(C==n && C==0){
                L3=L3->next ,L2->next = NULL ;
                break;}
            else if(C==n){
                L2->next = L2->next->next;
                break;}
            C++;
            L2 = L2->next;
        }
        if(N==1)
            L3=NULL;
        return L3;
    }
};