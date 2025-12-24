class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxiArea = INT_MIN;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int width = (j - i);
            int mini = min(height[i], height[j]);
            int currArea = (width * mini);
            maxiArea = max(maxiArea, currArea);
            if(height[i] > height[j]) j--;
            else if(height[i] < height[j]) i++;

            else {
                i++;
                j--;
            }
        }
        return maxiArea;

    }
};