class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto it : asteroids) {
            if(it > 0) ans.push_back(it);
            
            while (!ans.empty() && it < 0 && ans.back() < abs(it) && ans.back() > 0) 
                ans.pop_back();
            
            if(!ans.empty() && ans.back() == abs(it) && it < 0) {
                ans.pop_back();
            }
            else if(ans.empty() || ans.back() < 0){
                ans.push_back(it);
            }
        }
        return ans;
    }
};