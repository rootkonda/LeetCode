/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

Explanation:
------------
Maintain a map between the old address and new adress of nodes we create every time. Whenever we don't find an old (random) address, put that old address of that node and its random address inside a map.

After processing all nodes, loop thru pending list of nodes and update the node's new address random pointer to new node.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* curr = head;
        Node* new_head=NULL;
        Node* prev=NULL;
        map<Node*,Node*> pending;
        map<Node*,Node*> comp;
        while(curr)
        {
            Node *temp=new Node(curr->val);
            if(new_head==NULL)
            {
                comp[curr] = temp;
                if(comp.count(curr->random))
                    temp->random = comp[curr->random];
                else if(curr->random)
                    pending[curr] = curr->random;
                new_head = temp;
            }
            else
            {
                comp[curr] = temp;
                if(comp.count(curr->random))
                     temp->random = comp[curr->random];
                else if(curr->random)
                     pending[curr] = curr->random;
                prev->next=temp;
            }
            prev=temp;
            curr = curr->next;
        }
        for(auto rand : pending)
            comp[rand.first]->random = comp[rand.second];
        return new_head;
    }
};

/*
[[7,null],[13,0],[11,4],[10,2],[1,0]]
[[1,1],[2,1]]
[[3,null],[3,0],[3,null]]
[]
*/
