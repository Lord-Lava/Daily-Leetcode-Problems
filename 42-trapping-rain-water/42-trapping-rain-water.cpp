class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int prev[n];
        int next[n];
        
        next[n-1] = height[n-1];
        prev[0] = height[0];
        
        for(int i = 1;i<n;i++){
            prev[i] = max(prev[i-1],height[i]);
        }
        
        for(int i = n-2;i>=0;i--){
            next[i] = max(next[i+1] , height[i]);
        }
        
        for(int i =0;i<n;i++){
            ans+= (min(next[i],prev[i]) - height[i]);
        }
        
        return ans;
    }
};