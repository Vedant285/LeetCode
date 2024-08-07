class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = 0, rMax = 0, total = 0;
        int l = 0; int r = height.size() - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                if(height[l] < lMax) {
                    total += lMax - height[l];
                }
                else {
                    lMax = height[l];
                }
                l++;
            }
            else {
                if (height[r] < rMax) {
                    total += rMax - height[r];
                }
                else {
                    rMax = height[r];
                }
                r--;
            }
        }   
        return total;
    }
};