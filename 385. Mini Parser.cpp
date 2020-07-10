/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].

*/
class Solution {
public:
    NestedInteger deserialize(string s,int start=0) 
    {
        stack<NestedInteger> stk;
        string num="";
        stk.push(NestedInteger()); // Keep a starting object
        for(auto ch : s)
        {
            if(ch==']') //Whenever we see ], pop the object and add a new object with the number we have
            {
                NestedInteger ni = stk.top();
                stk.pop();
                if(num.size())
                    ni.add(NestedInteger(stoi(num)));
                stk.top().add(ni); //Add this to object which is in the stack.
                num="";
            }
            else if(isdigit(ch) or ch=='-')
                num.push_back(ch); // prepare the number
            else if(ch==',' and num.size())
            {
                stk.top().add(NestedInteger(stoi(num))); // add this to the existing object in the stack.
                num="";
            }
            else if(ch=='[')
                stk.push(NestedInteger());
        }
        if(num.size())
            stk.top().add(NestedInteger(stoi(num))); If there is a num at the last then add it to the existing stack object
        return stk.top().getList().front(); // Get the list and return the pointer to the front or first object
    }
};
