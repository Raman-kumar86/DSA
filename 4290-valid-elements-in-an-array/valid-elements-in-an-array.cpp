class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            bool f1 = true, f2 = true;
            for(int j=0;j<n;j++){
                if(j<i && nums[j]>=nums[i]){
                    f1 = false;
                }
                if(j>i && nums[j]>=nums[i]){
                    f2 = false;
                }
            }
            if(f1 || f2) ans.push_back(nums[i]);
        }
        return ans;
    }
};