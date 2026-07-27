class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        int second_maxi = 0;
        for(int num:nums){
            if(num>=maxi){
                second_maxi = maxi;
                maxi = num;
            }else if(num>second_maxi){
                second_maxi = num;
            }
        }
        return (maxi-1)*(second_maxi-1);
    }
};