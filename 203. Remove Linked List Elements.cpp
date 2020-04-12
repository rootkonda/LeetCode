/**
Remove all elements from a linked list of integers that have value val.

Maintain two pointers(previous and current). When we see target element, keep looping until we find unique element. Set the previous next to current pointer and update previous and current pointers respectively.
**/

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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *ans=NULL,*curr,*prev=NULL;
        curr=head;
        bool hasval=false;
        while(curr!=NULL)
        {
            while(curr!=NULL and curr->val==val)
            {
                curr=curr->next;
                hasval=true;
            }
            if(prev==NULL)
                ans=curr;
            else if(hasval)
            {
                prev->next=curr;
                hasval=false;
            } 
            prev=curr;
            curr=curr!=NULL ? curr->next : curr;   
        }
        return ans;
    }
};
