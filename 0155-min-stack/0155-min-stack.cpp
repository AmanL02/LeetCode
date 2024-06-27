#include <stack>
using namespace std;

class MinStack {
public:
    long long min_element;
    stack<long long> s;

    MinStack() {
        min_element = LLONG_MAX;
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            min_element = val;
        } else {
            if (val >= min_element) {
                s.push(val);
            } else {
                s.push(2LL * val - min_element);
                min_element = val;
            }
        }
    }
    
    void pop() {
        if (s.empty()) return;

        if (s.top() >= min_element) {
            s.pop();
        } else {
            min_element = 2 * min_element - s.top();
            s.pop();
        }
        
        if (s.empty()) {
            min_element = LLONG_MAX;
        }
    }
    
    int top() {
        if (s.empty()) return -1;

        if (s.top() >= min_element) {
            return s.top();
        } else {
            return min_element;
        }
    }
    
    int getMin() {
        if (s.empty()) return -1;
        return min_element;
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
