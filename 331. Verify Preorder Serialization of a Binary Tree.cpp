/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

number,#,# - represents a leaf node. So when we see this pattern we replace this with '#' and then move on to next in the string input.
Whenever we see '#' character on top of stack and the current character is also '#', then we definetly have number,#,# pattern hence pop # and number and return false if we cant pop.
Finally push '#' to indicate that left or right subtree is processed.

*/

class Solution {
public:
    bool isValidSerialization(string str) 
    {
        stack<char> stk;
        str.push_back(',');
        char prev='a';
        for(auto c : str)
        {
            if(c=='#')
            {
                while(!stk.empty() and stk.top()=='#')
                {
                    stk.pop(); //pop '#'
                    if(stk.empty() or stk.top()=='#')
                        return false;
                    stk.pop();//pop number
                }
                stk.push('#');
            }
            else if(c==',' and isdigit(prev)) // current character is ',' and previous character is a digit then push it to the stack
                stk.push('n');
            prev=c;
        }
        return stk.size()==1 and stk.top()=='#'; // At the end we should only have 1 char '#'
    }
};
