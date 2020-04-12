/**
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Implemented using vector. Other way is to use two stacks. Every time we push, we can push it as normal and keep front element.
During pop, first pop all elements to stack 2, this will store it in reverse order and then pop. **/

**/


class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> stack;
    MyQueue() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stack.push_back(x);        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t=stack[0];
        vector<int> temp;
        for(int i=1;i<stack.size();i++)
            temp.push_back(stack[i]);
        stack=temp;
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        return stack[0];
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
