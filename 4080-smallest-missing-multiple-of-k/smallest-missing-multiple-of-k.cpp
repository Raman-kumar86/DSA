class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int num = k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<num) continue;
            if(num<nums[i]) return num;
            num = num + k;
        }
        return num;
    }
};