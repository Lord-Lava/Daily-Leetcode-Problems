class Solution {
public:
    int dp[101];
    int house_robber(vector<int>&nums,int s,int n){
        if(n<=s) return 0;
        if(dp[n-1]!=-1)return dp[n-1];
        return dp[n-1] = max( 
           (nums[n-1] + house_robber(nums,s,n-2)) , house_robber(nums,s,n-1)
        );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        memset(dp,-1,sizeof(dp));
        int a = house_robber(nums,0,n-1);
        memset(dp,-1,sizeof(dp));
        int b = house_robber(nums,1,n);
        return max(a,b);
    }
};