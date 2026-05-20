class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>freq;
        int n = A.size();
        vector<int>result(n);
        int common = 0;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2) common++;
            freq[B[i]]++;
            if(freq[B[i]]==2) common++;
            result[i] = common;
        }
        return result;
    }
};