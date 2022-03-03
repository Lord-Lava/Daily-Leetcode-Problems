class Solution {
public:
    int t[101];
    
    int rob_util(vector<int>&nums, int n){
        if(n<=0) return 0;
        
        if(t[n-1]!=-1) return t[n-1];
        
        return t[n-1] = max(nums[n-1] + rob_util(nums,n-2),rob_util(nums,n-1));
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return rob_util(nums,n);
    }
};