class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2) return false;
        unordered_map<char, int>um1, um2; 
        for(int i=0;i<n1;i++){
            if(um1.count(s[i]) && um1[s[i]]!=t[i]) return false;
            if(um2.count(t[i]) && um2[t[i]]!=s[i]) return false;
            um1[s[i]] = t[i];
            um2[t[i]] = s[i];
        }
        return true;
    }
};