class Solution {
    void fun(int i,vector<int>& candidates,vector<vector<int>>&res,vector<int>&ds,int target){
        if(i==candidates.size()){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            fun(i,candidates,res,ds,target-candidates[i]);
            ds.pop_back();
        }
        fun(i+1,candidates,res,ds,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>res;
        vector<int>ds;
        fun(0,candidates,res,ds,target);
        return res;
    }
};