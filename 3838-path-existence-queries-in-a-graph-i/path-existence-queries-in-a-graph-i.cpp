class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
        if(parent_u==parent_v) return;
        if(rank[parent_u]>rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u]<rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                Union(i, i-1);
            }
        }
        vector<bool>ans(queries.size(), false);
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int p1 = find(u);
            int p2 = find(v);
            if(p1==p2) ans[i] = true;
        }
        return ans;
    }
};