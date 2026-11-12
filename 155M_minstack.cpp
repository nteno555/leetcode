class MinStack {
private:
    stack<int> vals;
    stack<int> mins;
public:
    MinStack() {
    }

    void push(int value) {
        if (vals.empty()) {
            vals.push(value);
            mins.push(value);
        } else {
            vals.push(value);
            mins.push(min(mins.top(), value));
        }
    }

    void pop() {
        mins.pop();
        vals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return mins.top();
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