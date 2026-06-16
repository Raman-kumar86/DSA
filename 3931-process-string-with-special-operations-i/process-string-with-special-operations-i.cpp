class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!st.empty()){
                    st.pop();
                }
            }else if(s[i]=='#'){
                string str1 = "";
                while(!st.empty()){
                    str1 += st.top();
                    st.pop();
                }
                reverse(str1.begin(), str1.end());
                int j=2;
                while(j>0){
                    for(char c:str1){
                        st.push(c);
                    }
                    j--;
                }
            }else if(s[i]=='%'){
                string str1 = "";
                while(!st.empty()){
                    str1 += st.top();
                    st.pop();
                }
                for(char c:str1){
                    st.push(c);
                }
            }else{
                st.push(s[i]);
            }
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};