class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int temp = nums[0];
        unordered_set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=temp+1){
                break;
            }
            sum += nums[i];
            temp++;
        }
        int ans = sum;
        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};