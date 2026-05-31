class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        unsigned long long m = mass;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(m<asteroids[i]) return false;
            m += asteroids[i];
        }
        return true;
    }
};