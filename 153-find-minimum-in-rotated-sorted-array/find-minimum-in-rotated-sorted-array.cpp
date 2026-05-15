class Solution {
public:
    int binarySearch(vector<int>nums,int start,int end){
        if(start==end){
            return nums[start];
        }
        int mid=start+(end-start)/2;
        if(nums[mid]>nums[end]){
            return binarySearch(nums,mid+1,end);
        }else{
            return binarySearch(nums,start,mid);
        }
    }
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        return binarySearch(nums,start,end);
    }
};