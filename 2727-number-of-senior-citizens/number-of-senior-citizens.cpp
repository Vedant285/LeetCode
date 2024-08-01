class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto it : details) {
            string s = it.substr(11, 2);
            int f = stoi(s);
            if(f > 60) {
                ans++;
            }
        }
        return ans;
    }
};