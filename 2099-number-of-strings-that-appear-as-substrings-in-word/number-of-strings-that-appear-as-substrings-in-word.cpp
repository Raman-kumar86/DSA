class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string>st;
        int n = word.size();
        for(int i=0;i<n;i++){
            string str1 = "";
            for(int j=i;j<n;j++){
                str1 += word[j];
                st.insert(str1);
            }
        }
        int ans = 0;
        for(string str:patterns){
            if(st.count(str)) ans++;
        }
        return ans;
    }
};