class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>ans;
        int n=dist.size();
        for(int i=0;i<n;i++){
            int time=(dist[i]-1)/speed[i];
            ans.push_back(time);
        }
        sort(begin(ans),end(ans));
        for(int i=0;i<n;i++){
            if(i>ans[i])return i;
        }
        return n;
    }
};