/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

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
     ListNode* partition(ListNode* head, int x)
     {
         ListNode* curr=head;
         ListNode* last=NULL; // To maintain the last node where the element is greater or equals to x
         ListNode* prev=NULL; // To maintain the last node where the element is smaller
         while(curr!=NULL)
         {
             if(curr->val<x)
             {
                 if(prev!=NULL)
                 {
                     if(prev->next==curr) // To skip the nodes where they are already in the correct order
                     {
                         prev=curr;
                         continue;
                     }
                     ListNode* temp = prev->next;
                     prev->next = curr;
                     if(last!=NULL)
                        last->next = curr->next; // Connect the previous node of the smaller node to the next node of smaller node. 
                     curr->next = temp; // Inserting the smaller node between the last smaller node and its next node.
                 }
                 else if(last!=NULL) // When all elements till now are greater than or equal to x then no 'prev' pointer i.e. no smaller element. So insert it here.
                 {
                     ListNode* temp = head;
                     head = curr;
                     if(last!=NULL)
                        last->next = curr->next;
                     head->next = temp;
                 }
                 prev=curr; // If the element is smaller then just keep updating this node.
             }
             else
                 last=curr;
             curr = curr->next;
         }
         return head;
     }
 };
