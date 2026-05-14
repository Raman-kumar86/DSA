class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int score = 0;
        for(int i=0;i<n;i++){
            unordered_map<char, int>um;
            for(int j=i;j<n;j++){
                um[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto& it:um){
                    if(it.second>maxi) maxi = it.second;
                    if(it.second<mini) mini = it.second;
                }
                if(mini!=INT_MAX && maxi!=INT_MIN){
                    score += maxi-mini;
                }
            }
            
        }
        return score;
    }
};