class Solution {
public:
    int binary_search(int start,vector<pair<int,int>>&nums,int target){
        int lo = start;
        int hi = (int)nums.size()-1;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid].first == target){
                return nums[mid].second;
            }else if(nums[mid].first < target){
                lo = mid+1;
            }else if(nums[mid].first){
                hi = mid-1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        for(int i =0 ;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i = 0;i < (int)arr.size()-1; i++){
            int req = target - arr[i].first;
            int other_index = binary_search(i+1,arr,req);
            if(other_index!=-1){
                ans.push_back(arr[i].second);
                ans.push_back(other_index);
            }
        }
        return ans;
    }
};