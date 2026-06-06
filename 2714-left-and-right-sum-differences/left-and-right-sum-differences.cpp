class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        for(int i=1;i<n;i++){
            int ridx = n-i-1;
            leftSum[i] = leftSum[i-1] + nums[i-1];
            rightSum[ridx] = rightSum[ridx+1] + nums[ridx+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};