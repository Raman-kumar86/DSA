class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int freq = 0;
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(nums[j]==target) freq++;
                if(freq>len/2) result++;
            }
        }
        return result;
    }
};