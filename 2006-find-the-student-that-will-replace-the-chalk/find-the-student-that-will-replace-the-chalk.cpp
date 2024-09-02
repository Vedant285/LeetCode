class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        long long r = k % sum;
        long long n = chalk.size();
        for(long long i = 0; i < n; i++) {
            if(r <= 0 || r < chalk[i]) return i;
            r -= chalk[i];
        }
        return -1;
    }
};