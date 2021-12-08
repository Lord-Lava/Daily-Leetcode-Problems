class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[0];
        int maxi = INT_MIN;
        int ctr=1;
        for(int i=0;i<(int)nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ctr++;
            }else{
                ctr=1;
            }
            if(ctr>maxi){
                maxi = ctr;
                ans = nums[i];
            }
        }
        
        return ans;
    }
};