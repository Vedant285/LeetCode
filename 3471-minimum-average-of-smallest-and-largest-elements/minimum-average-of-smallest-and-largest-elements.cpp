class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        std::vector<double> averages;
    
        std::sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int minElement = nums[i];
            int maxElement = nums[n - 1 - i];

            double average = (minElement + maxElement) / 2.0;
            averages.push_back(average);
        }

        double minAverage = *std::min_element(averages.begin(), averages.end());

        return minAverage;
    }
};