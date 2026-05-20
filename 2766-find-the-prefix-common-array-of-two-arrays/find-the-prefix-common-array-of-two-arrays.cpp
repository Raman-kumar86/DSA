class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        int num = 0;
        while(idx1<n1 && idx2<n2){
            if(nums1[idx1]==nums2[idx2]) {
                num++;
                idx1++;
                idx2++;
            }
            else if(nums1[idx1]<nums2[idx2]) idx1++;
            else idx2++;
        }
        return num;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            vector<int>nums1,nums2;
            nums1.assign(A.begin(), A.begin()+i+1);
            nums2.assign(B.begin(), B.begin()+i+1);
            result[i] = getCommon(nums1, nums2);
        }
        return result;
    }
};