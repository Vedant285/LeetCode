#define ll long long
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        ll n = energy.size();
        ll maxi = INT_MIN;
        for (ll i = n-1; i>=n-k ; i--) {
            ll cnt = 0;
            for (ll j = i ; j>=0 ; j-=k) {
                cnt+=energy[j];
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};