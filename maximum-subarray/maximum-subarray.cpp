class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int curS=0;
        for(int i=0;i<n;i++){
            curS+=nums[i];
            mx = max(mx,curS);
            if(curS<0){
                curS=0;
            }
        }
        return mx;
    }
};