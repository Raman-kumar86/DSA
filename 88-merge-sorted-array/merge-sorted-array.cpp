class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = 0, idx2 = 0;
        vector<int>arr;
        while(idx1<m && idx2<n){
            if(nums1[idx1]<=nums2[idx2]){
                arr.push_back(nums1[idx1]);
                idx1++;
            }else{
                arr.push_back(nums2[idx2]);
                idx2++;
            }
        }
        while(idx1<m){
            arr.push_back(nums1[idx1]);
            idx1++;
        }
        while(idx2<n){
            arr.push_back(nums2[idx2]);
            idx2++;
        }
        nums1 = arr;
    }
};