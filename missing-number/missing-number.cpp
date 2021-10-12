class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int _xor = n;
        for(int i=0;i<n;i++){
            _xor^=i;
            _xor ^= nums[i];
        }
        return _xor;
    }
};