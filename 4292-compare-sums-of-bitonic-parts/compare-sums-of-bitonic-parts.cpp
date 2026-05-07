class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long ascSum = nums[0];
        long long dscSum = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ascSum += nums[i];
                dscSum = nums[i];
            }else{
                dscSum += nums[i];
            }
        }
        if(ascSum>dscSum) return 0;
        else if(ascSum<dscSum) return 1;
        return -1;
    }
};