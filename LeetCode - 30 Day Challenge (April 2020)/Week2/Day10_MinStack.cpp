class MinStack {
    stack<pair<int,int>> st;
    int min = INT_MAX;
        
        
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(min > x)
            min = x;
        
        st.push({x,min});
    }
    
    void pop() {
        st.pop();
       
        if(st.empty())
            min = INT_MAX;
        else
            min = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
