class Solution {
public:
    int arr[1001][1001];
    bool solve(int i, int j, string& s){
        if(i>=j) return arr[i][j]=1;
        if(arr[i][j]!=-1) return arr[i][j];
        if(s[i]==s[j]){
            return arr[i][j]=solve(i+1,j-1,s);
        }
        return arr[i][j]=0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(arr,-1, sizeof(arr));
        int maxi = INT_MIN;
        int start = -1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s) && j-i+1>maxi){
                    maxi = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start,maxi);
    }
};