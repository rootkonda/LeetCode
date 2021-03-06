/**
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
  
  Approach:
  
  Compare each element in list1 and list2. Whichever is less or equal, make that node's next to NULL and move the pointer
  to the next node. Make sure to store the next node's address before making the node's next to NULL. **/
  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *lNext,*rNext,*last=NULL,*head=NULL;
            
        while(l1!=NULL and l2!=NULL)
        {
            lNext=l1->next;
            rNext=l2->next;
            if(l1->val>l2->val)
            {
                if(last==NULL)
                {
                    l2->next=last;
                    last=l2;
                    head=l2;
                }
                else
                {
                    last->next=l2;
                    last->next->next=NULL;
                    last=l2;
                }
                l2=rNext;
            }
            else if(l1->val<=l2->val)
            {
                if(last==NULL)
                {
                   l1->next=last;
                   last=l1;
                   head=l1;
                }
                else
                {
                    last->next=l1;
                    last->next->next=NULL;
                    last=l1;
                }
                l1=lNext;
            }
        }
        if(l1!=NULL)
        {
            if(last==NULL)
                head=l1;
            else
                last->next=l1;
        }
            
        if(l2!=NULL)
        {
            if(last==NULL)
                head=l2;
            else
                last->next=l2;
        }
        return head;
    }
};
