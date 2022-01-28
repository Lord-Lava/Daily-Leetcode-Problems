class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>next;
        for(int i = 0; i<n;i++){
            int j = (i+1)%n;
            int fl = 0;
            while(j!=i and nums[j]<=nums[i]){
                j = (j+1)%n;
            }
            if(j==i){
                next.push_back(-1);
            }else{
                next.push_back(nums[j]);
            }
        }
        return next;
    }
};