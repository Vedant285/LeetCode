
#define ll long long
#define vi vector<int>
#define si stack<ll>
#define sz(x) x.size()
int n;
class Solution {
public:

    ll minimum(vi& arr) {
        ll ans = 0;
        
        auto nge = [&](vi& arr) {
            si st;
            vi t1(n);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] <= arr[i])
                    st.pop();
                t1[i] = st.empty() ? n : st.top();
                st.push(i); 
            }
            return t1;
        };
        auto pgee = [&](vi& arr) {
            si st;
            vi t2(n);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] < arr[i])
                    st.pop();
                t2[i] = st.empty() ? -1 : st.top();
                st.push(i); 
            }
            return t2;
        };

        vi NGE = nge(arr);
        vi PGEE = pgee(arr);
        for (int i = 0; i < n; i++) {
            int l = i - PGEE[i];
            int r = NGE[i] - i;
            ans = (ans + (l * r * 1LL *arr[i]));
        }
        return ans;
    }

    ll maximum(vi& arr) {
        ll ans = 0;
        
        auto nse = [&](vi& arr) {
            si st;
            vi t1(n);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                t1[i] = st.empty() ? n : st.top();
                st.push(i); 
            }
            return t1;
        };
        auto psee = [&](vi& arr) {
            si st;
            vi t2(n);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                t2[i] = st.empty() ?-1 : st.top();
                st.push(i); 
            }
            return t2;
        };

        vi NSE = nse(arr);
        vi PSEE = psee(arr);
        for (int i = 0; i < n; i++) {
            int l = i - PSEE[i];
            int r = NSE[i] - i;
            ans = (ans + (l * r * 1LL * arr[i]));
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        n = sz(nums);
        return minimum(nums) - maximum(nums);
    }
};