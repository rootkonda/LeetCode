/**
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

Move two pointers until they are equal and their last node values are same or until the last node's value is not equal when 
there is no intersection.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL or headB==NULL)
            return NULL;
        ListNode *currA=headA,*currB=headB;
        int valA,valB,lastA=-1,lastB=-1;
        while(currA!=currB)  
        {
            if(currA==NULL)
            {
                currA=headB;
                if(lastA==valA)
                    break;
                lastA=valA;
            }
            else
            {
                valA=currA->val;
                currA=currA->next;
            }
            if(currB==NULL)
            {
                currB=headA;
                if(lastB==valB)
                    break;
                lastB=valB;
            }
            else
            {
                valB=currB->val;
                currB=currB->next;
            }
        }
        if(currA==currB and lastA==lastB)
            return currA;
        else
            return NULL;
    }
};
