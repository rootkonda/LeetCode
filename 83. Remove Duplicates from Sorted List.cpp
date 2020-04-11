/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

Have two pointers last and curr. Every time increment curr pointer and keep comparing two elements. When they are not same
update the last pointer's next to use the curr pointer.**/

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
            return head;
        ListNode *last=head;
        ListNode *curr=head;
        
        while(curr!=NULL and curr->next!=NULL)
        {
            if(curr->val!=curr->next->val)
            {
                last->next=curr->next;
                last=curr->next;
            }
            curr=curr->next;
        }
        last->next=NULL;
        return head;
    }
};
