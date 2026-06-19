class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = 0;
        int num = 0;
        for(int i:gain){
            num += i;
            maxi = max(maxi, num);
        }
        return maxi;
    }
};