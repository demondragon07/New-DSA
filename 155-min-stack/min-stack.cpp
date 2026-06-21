class MinStack {
public:
long long mini;
stack<long long>st;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini=value;
        }
       else if(value<mini){
           long long newval=(2LL*value)-mini;
            st.push(newval);
            mini=value;
        } 
        else st.push(value);
    }
    
    void pop() {
        if(st.empty())return;
        else if(st.top()<mini){
            mini=2*mini-st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        else if(st.top()>mini) return st.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
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