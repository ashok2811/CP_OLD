/*

Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.


*/


class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<pair<int , int>> s;
    MinStack() { }
    
    void push(int x) {
        if(s.empty()){
            s.push({x,x});
        }
        else{
            s.push({x , min(x, s.top().second)});
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};