class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>>pq;

        for (auto it : classes) {
            int a = it[0];
            int b = it[1];

            pq.push({double(a+1)/(b+1) - (double)a / b , {a, b}});
        }

        while (extraStudents-- ) {
            auto it = pq.top();
            pq.pop();
            int a = it.second.first + 1;
            int b = it.second.second + 1;
            double g = double(a+1)/(b+1) - (double)a/b;
            pq.push({ g, {a, b}});
        }
        int n = classes.size();
        double ans = 0.0;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int a = it.second.first;
            int b = it.second.second;
            ans += (double)a / b;
        }
        return ans/n;
    }
};