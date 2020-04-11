/**
  Given a linked list, determine if it has a cycle in it.

  To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

  Starting from head, every time change the node's next pointer to point to itself and just move forward. This process 
  repeats until it reaches NULL or till it has a cycle where node points to itself.
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
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL or head->next==NULL)
            return false;
        ListNode *s=head;
        s=head->next;
        head->next=head;
        while(s!=s->next)
        {
            ListNode *t;
            t=s->next;
            s->next=s;
            s=t;
            if(s==NULL)
                return false;
        }
        return true;
    }
};
