class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>upper(26,false),lower(26,false);
        vector<int>upperIdx(26,-1),lowerIdx(26,-1);
        int n = word.size();
        for(int i=0;i<n;i++){
            int idx;
            char c = word[i];
            if(isupper(c)){
                idx = c-'A';
                upper[idx] = true;
                if(upperIdx[idx]==-1){
                    upperIdx[idx] = i;
                }
            }else{
                idx = c-'a';
                lower[idx] = true;
                lowerIdx[idx] = i;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(upper[i] && lower[i] && upperIdx[i]>lowerIdx[i]) ans++;
        }
        return ans;
    }
};