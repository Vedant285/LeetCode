class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> mp;

        int n = s.size();
        int sizet = n / k;

        for (int i = 0; i < n; i+= sizet) {
            string temp = s.substr(i, sizet);
            mp[temp]++;
        }

        for (int i = 0; i < n; i+= sizet) {
            string temp = t.substr(i, sizet);
            if(mp.find(temp) == mp.end()) return false;
            mp[temp]--;
            if(mp[temp] == 0) mp.erase(temp);
        }

        return true;

    }
};