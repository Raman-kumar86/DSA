class Solution {
public:
    int n;
    bool recurr(int i, vector<int>&arr, vector<bool>& visited){
        if(i<0 || i>=n || visited[i]) return false;
        if(arr[i]==0) return true;
        visited[i] = true;
        return recurr(i+arr[i], arr, visited) || recurr(i-arr[i],arr, visited);
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool>visited(n, false);
        return recurr(start, arr, visited);
    }
};