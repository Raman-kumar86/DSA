class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool flag = true;
        for(int num:nums){
            if(num>=0) {
                flag = false;
                break;
            }
        }
        if(flag) return *max_element(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int temp = 0;
        for(int num:nums){
            temp += num;
            if(temp<0) temp = 0;
            maxi = max(temp, maxi);
        }
        return maxi;
    }
};