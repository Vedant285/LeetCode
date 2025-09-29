class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long temp = 1;

        while (n > 0) {

            int t = n%10;
            int k = t * temp;
            if(k != 0) ans.push_back(k);
            temp *= 10;
            n /= 10;        
        }   
        reverse(ans.begin(), ans.end());
        return ans;
    }
};