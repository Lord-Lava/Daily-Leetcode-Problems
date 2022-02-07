class StockSpanner {
    stack<pair<int,int>>st;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        bool flag = 0;
        int ans = 1;
        while(!st.empty() && st.top().second<=price){
            st.pop(); 
            flag = 1;
        }
        if(st.empty() && flag ==1){
            ans = index+1;
        }
        if(!st.empty()){
            ans = index - st.top().first;
        }
        
        st.push({index,price});
        index++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */