class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int votes = 0;
        for(int num:nums){
            if(votes==0){
                candidate = num;
                votes = 1;
                continue;
            }
            if(num==candidate) votes++;
            else votes--;
        }
        return candidate;
    }
};