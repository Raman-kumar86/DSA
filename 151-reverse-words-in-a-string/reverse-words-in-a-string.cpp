class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>arr;
        string key;
        while(ss>>key){
            arr.push_back(key);
        }
        reverse(arr.begin(),arr.end());
        string ans = "";
        for(string str1:arr){
            ans += str1 + " ";
        }
        int n = ans.size();
        int end = n-1;
        while(n>=0 && ans[end]==' ') end--;
        return ans.substr(0, end+1);
    }
};