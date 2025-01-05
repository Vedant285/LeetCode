class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pre(n + 1, 0);
        for (auto it : shifts) {
            int l = it[0];
            int r = it[1] + 1;
            int dir = it[2];

            if(dir == 0) {
                pre[l]--;
                pre[r]++;
            }
            else {
                pre[l]++;
                pre[r]--;
            }
        }

        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int mov = (pre[i] % 26 + 26) % 26;
            s[i] =  'a' + (s[i] - 'a' + mov) % 26;
        }
        return s;
    }
};