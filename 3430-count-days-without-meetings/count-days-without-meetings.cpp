#define ll long long
#define ff(i, s, e) for (ll i = s ; i < e ; i++)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
         if (meetings.empty()) return days;

        sort(begin(meetings), end(meetings));
        int n = meetings.size();
        vector<pair<ll, ll>> mi;
        int cs = meetings[0][0];
        int ce = meetings[0][1];

        ff (i, 1, n) {
            if (meetings[i][0] <= ce + 1) {
                ce = max(ce, meetings[i][1]);
            } else {
                mi.push_back({cs, ce});
                cs = meetings[i][0];
                ce = meetings[i][1];
            }
        }
        mi.push_back({cs, ce});

        ll cnt = 0;

        if (mi[0].first > 1) {
            cnt += mi[0].first - 1;
        }
        int m = mi.size();
        ff (i, 1, m) {
            cnt += mi[i].first - mi[i - 1].second - 1;
        }

        if (mi.back().second < days) {
            cnt += days - mi.back().second;
        }

        return cnt;
    }
};