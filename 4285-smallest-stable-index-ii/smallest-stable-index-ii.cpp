class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int>mini(n);
        int minimum = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<minimum){
                minimum = nums[i];
            }
            mini[i] = minimum;
        }
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi = nums[i];
            }
            int score = maxi - mini[i];
            if(score<=k) return i;
        }
        return -1;
    }
};