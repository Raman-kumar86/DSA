class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int lMax = height[left];
        int rMax = height[right];
        int ans = 0;
        while (left < right) {
            if (lMax <= rMax) {
                left++;
                lMax = max(lMax, height[left]);
                ans += lMax - height[left];
            } else {
                right--;
                rMax = max(rMax, height[right]);
                ans += rMax - height[right];
            }
        }
        return ans;
    }
};
