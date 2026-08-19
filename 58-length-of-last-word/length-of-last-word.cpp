class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        stringstream ss(s);
        string str1;
        while(ss>>str1){
            length = str1.size();
        }
        return length;
    }
};