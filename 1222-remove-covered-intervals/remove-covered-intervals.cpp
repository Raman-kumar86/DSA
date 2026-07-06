class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[&](auto& a, auto& b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        int n = intervals.size();
        int ans = 0;
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        for(int i=1;i<n;i++){
            int temp_min = intervals[i][0];
            int temp_max = intervals[i][1];
            if(temp_min>= mini && temp_max<=maxi){
                ans++;
                continue;
            }
            mini = temp_min;
            maxi = temp_max;
        }
        return n-ans;
    }
};