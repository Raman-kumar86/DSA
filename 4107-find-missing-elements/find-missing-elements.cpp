class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = nums[0];
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=first){
                ans.push_back(first);
                i--;
            }
            first++;
        }
        return ans;
    }
};