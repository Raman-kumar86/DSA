class Solution {
public:
    bool odd(char c){
        int num = c -'0';
        return num & 1;
    }
    string largestOddNumber(string num) {
        int len = -1;
        int n = num.size();

        for(int i=n-1;i>=0;i--){
            char c = num[i];
            if(odd(c)){
                len = i;
                break;
            }
        }
        return len==-1 ? "" : num.substr(0, len+1) ;
    }
};