/**
  Reverse a singly linked list.
  
  We just have to reverse the links. For every node, keep track of last node and set the current node's next to last node.**/
  
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *curr=head,*prev=NULL,*next;
        while(curr!=NULL)
        {
            if(prev==NULL)
            {
                prev=curr;
                next=curr->next;
                prev->next=NULL;   
            } 
            else
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
            }
            curr=next;
        }
        return prev;
    }
};
