class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>um;
        int n = s.size();
        unordered_map<char,int>firstIdx;
        for(int i=0;i<n;i++){
            char c = s[i];
            um[c]++;
            if(!firstIdx.count(c)) firstIdx[c] = i;
        }
        sort(s.begin(),s.end(),[&](auto& c1, auto& c2){
            if(um[c1]==um[c2]){
                return firstIdx[c1]<firstIdx[c2];
            }
            return um[c1]>um[c2];
        });
        return s;
    }
};