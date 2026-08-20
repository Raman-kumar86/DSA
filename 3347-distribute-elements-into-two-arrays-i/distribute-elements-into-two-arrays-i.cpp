class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        int n = nums.size();
        int first = nums[0], second = nums[1];
        arr1.push_back(first);
        arr2.push_back(second);
        for(int i=2;i<n;i++){
            if(first>second){
                arr1.push_back(nums[i]);
                first = nums[i];
            }else{
                arr2.push_back(nums[i]);
                second = nums[i];
            }
        }
        vector<int>arr;
        for(int i=0;i<arr1.size();i++){
            arr.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            arr.push_back(arr2[i]);
        }
        return arr;
    }
};