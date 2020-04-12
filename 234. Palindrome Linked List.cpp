/**
Given a singly linked list, determine if it is a palindrome.

First loop to copy all the elements in same order into vector. Next loop is to compare linked list elements to vector elements.
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
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL)
            return true;
        ListNode *last=head;
        vector<int> list;
        while(last!=NULL)
        {
            list.push_back(last->val);
            last=last->next;
        }
        int idx=list.size()-1;
        last=head;
        while(last!=NULL)
        {
            if(last->val!=list[idx])
                return false;
            idx--;
            last=last->next;
        }
        return true;
    }
};
