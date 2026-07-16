class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](auto& a, auto& b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        vector<int>lis;
        for (int i = 0; i < envelopes.size(); i++) {
            int h = envelopes[i][1];
            int pos = lower_bound(lis.begin(), lis.end(), h) - lis.begin();
            if (pos == lis.size()) {
                lis.push_back(h);
            } else {
                lis[pos] = h;
            }
        }
        return lis.size();
    }
};