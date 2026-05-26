class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        unordered_map<int,vector<int>>um;
        for(int i=0;i<n;i++){
            um[arr[i]].push_back(i);
        }
        int steps = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int idx = q.front();
                if(idx==n-1) return steps;
                q.pop();
                if(idx+1<n && !visited[idx+1]){
                    visited[idx+1] = true;
                    q.push(idx+1);
                }
                if(idx-1>=0 && !visited[idx-1]){
                    visited[idx-1] = true;
                    q.push(idx-1);
                }
                vector<int>sameVal = um[arr[idx]];
                for(int i=0;i<sameVal.size();i++){
                    if(!visited[sameVal[i]]){
                        q.push(sameVal[i]);
                    }
                }
                um[arr[idx]].clear();
            }
            steps++;
        }
        return 0;
    }
};