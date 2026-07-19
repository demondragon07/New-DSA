class StockSpanner {
public:
    stack<pair<int,int>>st;
    int idx=-1;
    StockSpanner() {
    }
    
    int next(int price) {
        idx=idx+1;
        int cnt;
        while(!st.empty() && st.top().first<=price)st.pop();
        cnt=idx-(st.empty()?-1:st.top().second);
        st.push({price,idx});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */