class Solution {
public:
    string fun1(string str1){
        string ans = "";
        char prev = str1[0];
        int count = 1;
        for(int i=1;i<str1.size();i++){
            if(prev==str1[i]){
                count++;
                continue;
            }
            ans += (to_string(count) + prev);
            prev = str1[i];
            count = 1;
        }
        ans += (to_string(count) + prev);
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            ans = fun1(ans);
        }
        return ans;
    }
};