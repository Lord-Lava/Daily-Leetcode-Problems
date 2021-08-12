class Solution {
public:
    int solve(vector<int>nums,int n,int sum){
        int t[n+1][sum+1];
        memset(t,-1,sizeof(t));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j] = 0;
                }
                if(j==0){
                    t[i][j] = 1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j && nums[i-1]!=0){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot = 0;
        int numberofzeroes = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                numberofzeroes++;
            tot+=nums[i];
        }
        if((tot+target)&1) return 0;
        int sum = (tot+target)/2;
        return pow(2,numberofzeroes)*solve(nums,n,sum);
    }
};