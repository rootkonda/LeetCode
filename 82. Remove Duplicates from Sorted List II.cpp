/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.



**/


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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        ListNode* curr = head;
        ListNode* last = NULL;
        int duplicate = INT_MIN;
        if(head==NULL)
            return NULL;
        while(curr->next!=NULL)
        {
            if(curr->val!=curr->next->val and duplicate!=curr->val) // When two elements are different and the current value is not same as duplicate value.
            {
                if(last==NULL)
                {
                    last = curr;
                    head = last;
                }
                    
                else
                {
                    last->next=curr;
                    last = last->next;
                }
            }
            else
                duplicate = curr->val; // When two elements are same, then note the duplicate value
            curr = curr->next;
        }
        if(last!=NULL) // there is a list of unique elements
        {
            if(duplicate!=curr->val) // If the last element is not duplicate.
            {
                curr->next = NULL;
                last->next = curr;
            }
            else // If the last element is also duplicate
                last->next = NULL;
        }
        else if(duplicate!=curr->val)
            head = curr; // If only the last element is unique then point the head to last element.
        else
            head = NULL; // When all elements are duplicates
        return head;
    }
};
