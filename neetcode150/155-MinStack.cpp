class MinStack {
  // Time: O(1) for all operations (push, pop, top, getMin) because we are using two stacks to store the values and the minimum values. Each operation on the stacks (push and pop) takes O(1) time.
  // Space: O(n)
  public:
stack<int> stk; stack<int> minValue;

    MinStack() { }

    void push(int val) {
        stk.push(val);
        val = min(val, minValue.empty() ? val : minValue.top());
        minValue.push(val);
    }

    void pop() {
        stk.pop();
        minValue.pop();        
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minValue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */