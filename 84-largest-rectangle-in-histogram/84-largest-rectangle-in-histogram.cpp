class Solution {
public:
    vector<int> next_smaller_element(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n,n);
        stack<int>st;
        for(int i = n-1 ;i>=0 ;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty()){
                nse[i] = st.top();
            }
            
            st.push(i);
        }
        
        return nse;
    }
    
    vector<int> prev_smaller_element(vector<int>& heights){
        int n = heights.size();
        vector<int> pse(n,-1);
        stack<int>st;
        for(int i = 0 ;i<n ;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(!st.empty()){
                pse[i] = st.top();
            }
            
            st.push(i);
        }
        return pse;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int max_area = INT_MIN;
        int n = heights.size();
        vector<int> nse = next_smaller_element(heights);
        vector<int> pse = prev_smaller_element(heights);
        
        for(int i = 0; i < n ; i++){
            int height = heights[i];
            int width = nse[i] - pse[i] - 1;
            int area = height * width;
            
            max_area = max(max_area,area);
        }
        
        return max_area;
    }
};