class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int n = s.size();
        int num = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else{
                if(st.empty()){
                    num++;
                    continue;
                }
                st.pop();
            }
        }
        return st.size() + num;
    }
};