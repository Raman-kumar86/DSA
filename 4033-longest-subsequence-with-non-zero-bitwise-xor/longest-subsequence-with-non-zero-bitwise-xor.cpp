class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorResult = 0;
        bool allZero = true;
        for(int& num:nums){
            xorResult = (xorResult^num);
            if(num!=0){
                allZero = false;
            }
        }
        if(allZero) return 0;
        return xorResult==0?n-1:n;
    }
};