/**
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Below approach is not great. Use vector and always push the elements at the beginning of vector. Pop() from the beginning of vector and erase that element. Better way to do is:
1. Maintain two queues
2. Push elements into q1
3. Pop elements - Dequeue all the elements and push it to q2 until there is one element left in q1 and remove that. Copy back the q2 to q1.

**/

class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> queue;
    MyStack() 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);    
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        queue.insert(queue.begin(),x);    
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=queue[0];
        queue.erase(queue.begin());
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return queue[0];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
