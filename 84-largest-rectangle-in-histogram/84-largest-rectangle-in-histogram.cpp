class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        vector<int>nse(n,n);
        stack<int>st;
        
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
        
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        vector<int>pse(n,-1);
        stack<int>st;
        
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();
        vector<int>next = nse(heights), prev = pse(heights);
        
        for(int i = 0;i<n;i++){
            int base = next[i] - prev[i] - 1;
            int area = heights[i] * base;
            maxi = max(maxi,area);
        }
        return maxi;
    }
};