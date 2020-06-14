/*
Sort a linked list in O(n log n) time using constant space complexity.

https://leetcode.com/problems/sort-list/discuss/166324/c%2B%2B-and-java-legit-solution.-O(nlogn)-time-and-O(1)-space!-No-recursion!-With-detailed-explaination

*/

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
    ListNode* sortList(ListNode* head) 
    {
        int sz=0;
        ListNode* curr = head;
        while(curr)
        {
            sz++;
            curr=curr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail;
        ListNode* left;
        ListNode* right;
        
        for(int step=1;step<sz;step<<=1)
        {
            curr = dummy.next;
            tail = &dummy;
            while(curr)
            {
                left = curr;
                right = split(left,step);
                curr = split(right,step);
                tail = merge(left,right,tail);
            }
        }
        return dummy.next;
    }
    ListNode* split(ListNode* head,int n)
    {
        for(int i=1;head and i<n;i++)
            head = head->next;
        if(!head)
            return NULL;
        ListNode* second = head->next;
        head->next=NULL;
        return second;
    }
    ListNode* merge(ListNode* l1,ListNode* l2,ListNode* head)
    {
        ListNode* cur = head;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next)
            cur = cur->next;
        return cur;
    }
};
