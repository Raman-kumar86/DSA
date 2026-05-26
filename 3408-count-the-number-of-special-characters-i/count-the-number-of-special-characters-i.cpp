class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>upper(26,false),lower(26,false);
        for(char c:word){
            if(isupper(c)){
                upper[c-'A'] = true;
            }else{
                lower[c-'a'] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(upper[i] && lower[i]) ans++;
        }
        return ans;
    }
};