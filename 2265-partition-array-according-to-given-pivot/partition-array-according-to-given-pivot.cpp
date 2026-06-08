class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left,right;
        int pivotCount = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) left.push_back(nums[i]);
            else if(nums[i]>pivot) right.push_back(nums[i]);
            else pivotCount++;
        }
        int lsize = left.size();
        for(int i=0;i<lsize;i++){
            nums[i] = left[i];
        }
        for(int i=lsize;i<lsize+pivotCount;i++){
            nums[i] = pivot;
        }
        for(int i=0;i<right.size();i++){
            nums[lsize+pivotCount+i] = right[i];
        }
        return nums;
    }
};