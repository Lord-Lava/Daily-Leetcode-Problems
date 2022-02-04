class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>nge(n);
        
        for(int i = 2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();
            if(!st.empty()){
                nge[i%n] = st.top();
            }else{
                nge[i%n] = -1;
            }
            st.push(nums[i%n]);
        }
        
        return nge;
    }
};