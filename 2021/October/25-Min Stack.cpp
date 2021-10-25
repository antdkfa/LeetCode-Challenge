class MinStack {
public:
    stack<int> st;
    multiset<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        s.insert(val);
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        auto it = s.find(top);
        s.erase(it);
    }
    
    int top() {
        int top = st.top();
        return top;
    }
    
    int getMin() {
        auto it = s.begin();
        return *it;
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
