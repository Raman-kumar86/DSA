class Solution {
public:
    bool rotateString(string s, string goal) {
        int n2 = goal.size();
        int n1 = s.size();
        if(n2!=n1) return false;
        string str1 = s + s;
        for(int i=0;i+n1<2*n1;i++){
            string sub = str1.substr(i,n1);
            if(sub==goal) return true;
        }
        return false;
    }
};