class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>um;
        int n = text.size();
        for(int i=0;i<n;i++){
            um[text[i]]++;
        }
        string str1 = "balloon";
        int maxi = INT_MAX;
        for(int i=0;i<str1.size();i++){
            if(!um.count(str1[i])) return 0;
            int count = um[str1[i]];
            if(str1[i]=='l' || str1[i]=='o'){
                count = count/2;
            }
            maxi = min(maxi, count);
        }
        return maxi;
    }
};