class StockSpanner {
    stack<pair<int,int>>st;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int res = 1;
        bool fl = 0;
        while(!st.empty() && st.top().first<=price)
            st.pop(),fl=1;
        
        if(!st.empty())
            res = index - st.top().second;
        if(st.empty() && fl == 1)
            res = index+1;
        
        st.push({price,index});
        
        index++;
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */