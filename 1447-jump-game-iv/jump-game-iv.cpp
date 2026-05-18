class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int steps = 0;
        unordered_map<int,vector<int>>um;
        vector<bool>visited(n, false);
        for(int i=0;i<n;i++){
            um[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int idx = q.front();
                q.pop();
                if(idx==n-1) return steps;
                if(idx-1>=0 && !visited[idx-1]){
                    visited[idx-1] = true;
                    q.push(idx-1);
                }
                if(idx+1<n && !visited[idx+1]){
                    visited[idx+1] = true;
                    q.push(idx+1);
                }
                for(int i=0;i<um[arr[idx]].size();i++){
                    if(!visited[um[arr[idx]][i]]){
                        visited[um[arr[idx]][i]] = true;
                        q.push(um[arr[idx]][i]);
                    }
                }
                um[arr[idx]].clear();
            }
            steps++;
        }
        return -1;
    }
};