class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long cnt = mass;
        for (auto it:asteroids) {
            if (cnt < it){
                return false;
            }
            cnt += it;
        }
        return true;
    }
};