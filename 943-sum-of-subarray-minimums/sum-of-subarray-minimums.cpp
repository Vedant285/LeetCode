#define vi vector<int> 
#define si stack<int>
class Solution {
public:

    vi PSEE(vi& arr) {
        int n = arr.size();
        vi nsee(n);
        si st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            nsee[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        return nsee;
    }
    vi NSE(vi& arr) {
        int n = size(arr);
        vi ans(n);
        si st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vi nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            int l = i - psee[i];
            int r = nse[i] - i;
            ans = (ans + (l * r * 1LL * arr[i]) % mod) % mod;
        }
        return ans;
    }
};