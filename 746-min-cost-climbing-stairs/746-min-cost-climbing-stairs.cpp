class Solution {
    int minCost(int i,vector<int>&dp,int n,vector<int>&cost){
        if(i==n-1 || i==n-2) return cost[i];
    
        if(dp[i]!=-1)return dp[i];
        
        return dp[i] = min(
            cost[i] + minCost(i+1,dp,n,cost),
            cost[i] + minCost(i+2,dp,n,cost)
        );
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(1001,-1);
        int n = cost.size();
        return min(
            minCost(0,dp,n,cost),
            minCost(1,dp,n,cost)
        );
    }
};