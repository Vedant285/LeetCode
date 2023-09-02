class Solution {
public:
    int n;
    unordered_set<string>st;
    int solve(int idx,string s,vector<int>& dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string k="";
        int final=n;
        for(int i=idx;i<n;i++){
            k.push_back(s[i]);
            int curr=st.find(k)==st.end()?k.size():0;
            int next=solve(i+1,s,dp);
            int kp=curr+next;
            final=min(final,kp);
        }
        return dp[idx]=final;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto &it:dictionary){
            st.insert(it);
        }
        n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
};