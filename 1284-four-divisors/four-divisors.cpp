class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto &it : nums) {
            long long cnt = 0, sum2=0;

            for(int i=1;i<=sqrt(it);i++) {
                if(it%i ==0) {
                    if(i*i == it){
                        cnt++;
                        sum2 += i;
                    }
                    else {
                        cnt+=2;
                        sum2 += (i + it/i);
                    }
                }
                if(cnt > 4) break;
            }
            if(cnt == 4) {
                sum+=sum2;
            }
        }
        return sum;
    }
};