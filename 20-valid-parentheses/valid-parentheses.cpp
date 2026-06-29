class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        vector<pair<char,char>>paren={{'{','}'},{'(',')'},{'[',']'}};
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                for(auto p:paren){
                    if(p.second==s[i]){
                        if(p.first!=st.top()) return false;
                    }
                }
                st.pop();
            }else{
                st.push(s[i]);
            }

        }
        return st.empty();
    }
};