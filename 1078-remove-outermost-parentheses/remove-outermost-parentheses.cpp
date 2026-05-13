class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int i = 1;
        stack<int>st;
        string ans = "";
        while(i<n){
            if(s[i]=='('){
                st.push(1);
                ans += s[i];
                i++;
            }else{
                if(!st.empty()){
                    ans += s[i];
                    st.pop();
                    i++;
                }else{
                    i += 2;
                }
            }
        }
        return ans;
    }
};