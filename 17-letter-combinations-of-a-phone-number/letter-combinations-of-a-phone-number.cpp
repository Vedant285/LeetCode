class Solution {
public:
    vector<string>ans;
    void solve(int idx, string &digits, string temp,unordered_map<char, string>& mp ) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string k = mp[ch];
        for (int i = 0; i < k.size(); i++) {
            temp.push_back(k[i]);
            solve(idx + 1, digits, temp, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp, mp);
        return ans;
    }
};