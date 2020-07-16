/*
Design a stack which supports the following operations.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
int pop() Pops and returns the top of stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.

*/


class CustomStack {
public:
    stack<int> stk;
    vector<int> inc; // Maintins the list of increments to be made
    int sz;
    CustomStack(int maxSize) 
    {
        sz = maxSize;
        inc.resize(maxSize+1,0); // Allocate the memory and maintain the value to be incremented
    }
    void push(int x) 
    {
        if(stk.size()<sz) // Push only if there is enough space
            stk.push(x);    
    }
    
    int pop() 
    {
        if(stk.empty())
            return -1;
        int ans{stk.top()+inc[stk.size()]}; // Answer is whatever in top of stack + if there is any value to be incremented from inc vector
        inc[stk.size()-1]+=inc[stk.size()]; // propagate this value to its previous position and make this value as zero
        inc[stk.size()]=0; // set this value to zero
        stk.pop();
        return ans;
    }
    
    void increment(int k, int val) 
    {
        inc[min(k,(int)stk.size())]+=val;   // Just increment the value in corresponding position. 
    }
};
