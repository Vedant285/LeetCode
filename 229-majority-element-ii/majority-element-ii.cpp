class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = size(nums);
        int c1=0, c2=1;
        int cnt1=0, cnt2 = 0;
        for (auto it : nums) {
            if (c1 == it) {
                cnt1++;
            }
            else if (c2 == it) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                cnt1 = 1;
                c1 = it;
            }
            else if (cnt2 == 0) {
                cnt2 = 1;
                c2 = it;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ans;
        int a=0, b=0;
        for (auto it:nums) {
            if (it == c1) a++;
            else if(it == c2)b++;
        }
        if (a > n/3) ans.push_back(c1);
        if (b > n/3) ans.push_back(c2);
        return ans;
    }

};