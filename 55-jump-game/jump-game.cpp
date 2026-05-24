class Solution {
public:
    int n;
    int arr[10001];
    bool recurr(int idx, vector<int>&nums){
        if(idx>=n-1) return true;
        if(arr[idx]!=-1) return arr[idx];
        for(int i=1;i<=nums[idx];i++){
            if(recurr(idx+i,nums)) return arr[idx] = true;
        }
        return arr[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(arr, -1, sizeof(arr));
        return recurr(0, nums);
    }
};