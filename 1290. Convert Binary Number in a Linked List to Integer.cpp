/**
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Simple.

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
    int getDecimalValue(ListNode* head) 
    {
        int exp=-1;
        int res=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            exp++;
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->val)
                res+=pow(2,exp);
            exp--;
            curr=curr->next;
        }
        return res;
    }
};
