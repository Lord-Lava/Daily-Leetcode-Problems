class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        st.push(nums2[0]);
        map<int,int>mp;
        vector<int>res;
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        for(int i = 0; i < n2 ;i++ ){
            int next = nums2[i];
            while(!st.empty() && st.top()<next){
                mp[st.top()] = next;
                st.pop();
            }
            st.push(next);
        }
        
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        
        for(int i = 0;i<n1;i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};