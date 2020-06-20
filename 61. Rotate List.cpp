/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Firstly, prepare a vector of pairs with node's value and node's address and we also know the length of the list.
Secondly, (i+k)%n will give us the new position where i is the index and n is the length of list.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        vector<pair<int,ListNode*>> pos;
        if(k==0 or head==NULL)
            return head;
        int n=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            pos.push_back({curr->val,curr});
            curr=curr->next;
            
        }
        n = pos.size();
        if(k%n==0)
            return head;
        
        for(int i=0;i<n;i++)
            pos[(i+k)%n].second->val = pos[i].first;
        
        return head;
    }
};
/*
[78,98,40,23,25,26,49,45]
4
[1,2,3,4,5]
2
[0,1,2]
4
*/
