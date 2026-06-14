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
    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prevNode=nullptr;
        while(slow) {
            ListNode* nextNode=slow->next;
            slow->next=prevNode;
            prevNode=slow;
            slow=nextNode;
        }
        int maxSum=INT_MIN;
        ListNode* second=prevNode;
        while(head && second) {
            maxSum=max(maxSum,head->val+second->val);
            head=head->next;
            second=second->next;
        }
        return maxSum;
    }
};