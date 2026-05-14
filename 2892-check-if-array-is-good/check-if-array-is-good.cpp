class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        while(idx<n){
            int j = nums[idx]-1;
            if(j>=n) return false;
            if(nums[j]!=nums[idx]){
                swap(nums[idx], nums[j]);
                idx--;
            }
            idx++;
        }
        int x = 1;
        for(int i=0;i<n-1;i++){
            cout<<nums[i]<<" ";
            if(nums[i]!=x) return false;
            x++;
        }
        return nums[n-1]==n-1;
    }
};