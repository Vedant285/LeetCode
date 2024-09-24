class BIT{
public:
    vector<int> fen;
    int n;
    BIT(int N = 0) {
        n = N;
        fen.resize(N + 1, 0);
    }
    void addv(int t, int i) {
        while (i <= n) {
            fen[i] += t;
            i += (i & (-i));
        }
    }
    int getsum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += fen[i];
            i = (i - (i & (-i)));
        }
        return sum;
    }
};

class NumArray {
    BIT obj;
public:
    int n;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->obj = BIT(n);
        this->arr = nums;
        for (int i = 0; i < n; i++) {
            obj.addv(nums[i], i + 1);
        }
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        obj.addv(diff, index + 1);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return obj.getsum(right + 1) - obj.getsum(left);
    }
};