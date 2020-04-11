/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Push - check the minimum element from the back of the vector and keep track of it. Store the pair of element and a minimum value
till that point.

**/


class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int,int>> st;
    int min;
    MinStack() 
    {
    }
    void push(int x) 
    {
        if(st.empty())
            min=x;
        else if(st.back().second>=x)
            min=x;
        else
            min=st.back().second;
        st.push_back(make_pair(x,min));
    }
    void pop() {
        if(!st.empty())
            st.pop_back();
    }
    
    int top() {
        if(!st.empty())
            return st.back().first;
        else
            return 0;
    }
    
    int getMin() {
        if(!st.empty())
            return st.back().second;
        else
            return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
