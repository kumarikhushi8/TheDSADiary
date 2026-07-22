/*
Problem: Min Stack
LeetCode: 155
Approach: Two Stacks
Time Complexity:
    push()   -> O(1)
    pop()    -> O(1)
    top()    -> O(1)
    getMin() -> O(1)
Space Complexity: O(n)
*/

class MinStack {
public:
stack<int>st;
stack<int>minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minStack.empty() || minStack.top()>=value){
            minStack.push(value);
        }
    }
    
    void pop() {
        if(st.top()==minStack.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
