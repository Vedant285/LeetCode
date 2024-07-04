#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        ll n = spells.size();
        ll m = potions.size();
        
        vector<int> ans;
        for (ll i = 0 ; i < n ;i++) {
            ll mul = spells[i];
            ll cnt = 0;
            
            ll l = 0, h = m-1;
            while (l <= h) {
                ll mid = (h + l) / 2;
                ll lp = potions[mid] * mul;
                if (lp >= success) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            ans.push_back(m - l);
        }
        return ans;
    }
};