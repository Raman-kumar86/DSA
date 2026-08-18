class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1) {
            unordered_map<int, int> freq;
            for (int x : nums) {
                freq[x]++;
            }
            int ans = -1;
            for (auto &it : freq) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        int first = nums[0];
        int last = nums[n - 1];
        bool f = true;
        bool l = true;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == first)
                f = false;

            if (nums[i] == last)
                l = false;
        }
        if (first == last)
            return -1;
        if (!f && !l)
            return -1;
        if (!f)
            return last;

        if (!l)
            return first;

        return max(first, last);
    }
};