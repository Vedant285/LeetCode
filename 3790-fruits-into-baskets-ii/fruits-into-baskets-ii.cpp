class Solution {
public:
    bool canPlace(int p, vector<int>& arr) {

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if(p <= arr[i]) {
                arr[i] = -1;
                return true;
            }
        }
        return false;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //sort(baskets.begin(), baskets.end());
        int cnt = 0;
        for (auto it : fruits) {
            if(canPlace(it, baskets)) {
                continue;
            }
            else {
                cnt++;
            }
        }
        return cnt;
    }
};