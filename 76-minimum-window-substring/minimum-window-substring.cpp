class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), r = 0, l = 0, miniIndex = -1, maxi = INT_MAX, cnt = 0;
        unordered_map<char, int>mp;
        int m = t.size();
        for (auto it : t) {
            mp[it]++;
        }
        while (r < n) {
            if (mp[s[r]] > 0) cnt++;
            mp[s[r]] --;
            while (cnt == m){
                if (r - l + 1 < maxi){
                    maxi = r - l + 1;
                    miniIndex = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return miniIndex != -1 ? s.substr(miniIndex, maxi) : "";
        
    }
};