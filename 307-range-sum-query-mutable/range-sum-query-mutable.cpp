class NumArray {
public:
    int n;
    vector<int>bit, arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        this->n = nums.size();
        bit.resize(n + 1, 0);
        for (int i = 0;i < n; i++) {
            add(i + 1, nums[i]);
        }    
    }
    void add(int i, int nums) {
        while (i <= n) {
            bit[i] += nums;
            i += (i & (-i));
        }
    }
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        add(index + 1, diff);
    }
    
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= (i & (-i));
        }
        return s;
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};