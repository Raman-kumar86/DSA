class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>&ans, vector<int>&output){
        ans.push_back(output);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(nums, i+1, ans, output);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums, 0, ans, output);
        return ans;
    }
};
