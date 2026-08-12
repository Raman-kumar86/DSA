class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int right = 0;
        unordered_map<int, int>um;
        int ans = 0;
        while(right<n){
            um[nums[right]]++;                
            while(left<right && um[nums[right]]>k){
                um[nums[left]]--;
                left++;
            }
            int wsize = right-left+1;
            ans = max(ans, wsize);
            right++;
        }
        return ans;
    }
};