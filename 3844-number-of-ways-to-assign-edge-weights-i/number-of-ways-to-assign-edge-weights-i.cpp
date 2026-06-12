class Solution {
public:
    typedef long long LL;
    int M = 1e9 + 7;
    int power(LL base, LL exp){
        if(exp==0) return 1;
        LL half = power(base, exp/2);
        LL result = (half*half)%M;
        if(exp%2!=0) result = (result*base)%M;
        return result;
    }
    int maxDepth(unordered_map<int, vector<int>>&adj, int node, int parent){
        int depth = 0;
        for(auto& nbr:adj[node]){
            if(nbr==parent) continue;
            depth = max(depth, maxDepth(adj, nbr, node)+1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        int d = maxDepth(adj, 1, -1);
        return power(2, d-1);
    }
};