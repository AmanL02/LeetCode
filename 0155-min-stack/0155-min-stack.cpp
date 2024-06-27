class MinStack {
public:
    stack<int> st;
    stack<int> s;
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (st.size() == 0 || st.top() >= val) {
            st.push(val);
        }
    }

    void pop() {
        int temp = s.top();
        s.pop();
        if (st.top() == temp) {
            st.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        if (st.size() == 0)
            return -1;
        return st.top();
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