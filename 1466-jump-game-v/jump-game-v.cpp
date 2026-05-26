class Solution {
public:
    int n;
    int memo[1001];
    int solve(int idx, vector<int>& arr, int d){
        if(memo[idx]!=-1) return memo[idx];
        int result = 1;
        for(int j=idx-1;j>=max(0, idx-d);j--){
            if(arr[j]>=arr[idx]) break;
            result = max(result, 1 + solve(j, arr, d));
        }
        for(int j=idx+1;j<=min(n-1,idx+d);j++){
            if(arr[j]>=arr[idx]) break;
            result = max(result, 1 + solve(j, arr, d));
        }
        return memo[idx] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memset(memo, -1, sizeof(memo));
        int result = 1;
        for(int i=0;i<n;i++){
            result = max(result, solve(i, arr, d));
        }
        return result;
    }
};