class Solution {
public:
    int arr[501][501];
    int solve(int l, int r, vector<int>&cumSum){
        if(l>=r) return 0;
        if(arr[l][r]!=-1) return arr[l][r];
        int score = 0;
        for(int mid=l;mid<r;mid++){
            int leftSum = cumSum[mid] - (l-1>=0?cumSum[l-1]:0);
            int rightSum = cumSum[r] - cumSum[mid];
            if(leftSum>rightSum){
                score = max(score, rightSum+solve(mid+1,r, cumSum));
            }else if(rightSum>leftSum){
                score = max(score, leftSum+solve(l, mid, cumSum));
            }else{
                score = max({score, leftSum+solve(l, mid, cumSum), rightSum + solve(mid+1, r, cumSum)});
            }
        }
        return arr[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(arr, -1, sizeof(arr));
        vector<int>cumSum(n,0);
        cumSum[0] = stoneValue[0];
        for(int i=1;i<n;i++){
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }
        return solve(0, n-1, cumSum);
    }
};