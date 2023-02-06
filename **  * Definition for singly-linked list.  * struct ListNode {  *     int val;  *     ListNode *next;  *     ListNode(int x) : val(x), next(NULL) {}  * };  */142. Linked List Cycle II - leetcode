/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) 
            return NULL; 

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                break;
            }
        }
        if(!fast || !fast->next)return NULL;
        ListNode* curr=head;
        while(curr!=slow){
            slow=slow->next;
            curr=curr->next;
        }
        return curr;
    }
};
