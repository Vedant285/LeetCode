class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto it : logs) {
            if (it == "../") {
                if (ans > 0) {
                    ans--;
                } 
            }
            else if (it != "./") {
                ans ++;
            }
        }
        return ans;
    }
};