class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_set<int>st;
        for(int i=0;i<n1;i++){
            int x = arr1[i];
            st.insert(x);
            while(x>0){
                x = x/10;
                st.insert(x);
            }
        }
        int result = INT_MIN;
        for(int i=0;i<n2;i++){
            int y = arr2[i];
            while(y>0){
                if(st.count(y)){
                    int len = int(log10(y)) + 1;
                    result = max(result, len);
                }
                y = y/10;
            }
        }
        return result==INT_MIN ? 0: result;
    }
};