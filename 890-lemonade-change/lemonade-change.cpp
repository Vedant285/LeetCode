class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0;
        for (auto it : bills) {
            if (it == 5) f++;
            else if (it == 10) {
                if(f >= 1) {
                    f--;
                    t++;
                }
                else if (t >= 1) t--;
                else return false;
            }
            else {
                if (f >= 1 && t >= 1) {
                    t--;
                    f--;
                }
                else if (f >= 3 && t == 0) {
                    f-= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};