class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int right=n-1;
        int left=0;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};