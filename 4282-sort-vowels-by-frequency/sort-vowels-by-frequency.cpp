class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int>freq;
        unordered_set<char>st = {'a','e','i','o','u'};
        unordered_map<char,int>firstIdx;
        string vow = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.count(s[i])){
                continue;
            }
            vow += s[i];
            freq[s[i]]++;
            if(!firstIdx.count(s[i])){
                firstIdx[s[i]] = i;
            }
        }
        sort(vow.begin(),vow.end(),[&](auto& a, auto& b){
            if(freq[a]!=freq[b]){
                return freq[a]>freq[b];
            }
            return firstIdx[a]<firstIdx[b];
        });
        int idx = 0;
        for(int i=0;i<n;i++){
            if(st.count(s[i])){
                s[i] = vow[idx];
                idx++;
            }
        }
        return s;
    }
};