class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        int idx = 0;
        string str1 = "";
        for(char a='z';a>='a';a--){
            str1 += a;
        }
        for(string& str:words){
            int totalWt = 0;
            for(char c:str){
                int idx = c-'a';
                totalWt += weights[idx];
            }
            totalWt = totalWt%26;
            ans += str1[totalWt];
        }
        return ans;
    }
};