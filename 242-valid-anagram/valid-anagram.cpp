class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        vector<int> arr(26, 0);
        for (unsigned int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (auto it : arr) {
            if(it) return false;
        }
        return true;
    }
};