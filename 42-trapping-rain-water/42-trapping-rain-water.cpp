class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int prev[n];
        int next[n];
        
        int ans = 0;
        
        prev[0] = height[0];
        next[0] = height[n-1];
        
        for(int i=1;i<n;i++){
            prev[i] = max(prev[i-1],height[i]);
        }
        reverse(height.begin(),height.end());
        for(int i=1;i<n;i++){
            next[i] = max(next[i-1],height[i]);
        }
        
        for(int i=0;i<n;i++){
            ans+=min(next[n-i-1],prev[i]) - height[i];
        }
        
        return ans;
    }
};