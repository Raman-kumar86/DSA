class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0;
        for(char ch:s){
            if(ch=='*') len>0 ? len--: len;
            else if(ch=='#') len *= 2;
            else if(ch=='%') continue;
            else len++;
        }
        if(k>=len) return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*') len++;
            else if(s[i]=='%'){
                k = len - k - 1;
            }else if(s[i]=='#'){
                len = len/2;
                k = (k>=len) ? k-len : k;
            }else{
                len--;
            }
            if(len==k) return s[i];
        }
        return '.';
    }
};