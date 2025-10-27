class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = count(bank[0].begin(),bank[0].end(),'1');
        for (int i = 1; i < bank.size();i++) {
            int curr = count(bank[i].begin(),bank[i].end(), '1');

            if(curr == 0) continue;
            ans += (prev * curr);
            prev = curr;
            curr = 0;
        }
        return ans;
    }
};