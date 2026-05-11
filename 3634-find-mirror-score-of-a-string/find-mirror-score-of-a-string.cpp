class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<int, stack<int>>um;
        int n = s.size();
        long long score = 0;
        for(int i=0;i<n;i++){
            int req = 25 - (s[i]-'a');
            if(um.count(req)){
                int j = um[req].top();
                um[req].pop();
                if(um[req].empty()){
                    um.erase(req);
                }
                score += i-j;
                continue;
            }
            um[(s[i]-'a')].push(i);
        }
        return score;
    }
};