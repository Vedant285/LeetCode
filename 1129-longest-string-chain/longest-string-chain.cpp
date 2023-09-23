class Solution {
public:
    int n;
    bool check(string &a,string &b){
        int M=a.size();
        int N=b.size();

        if(M>=N || N-M!=1){
            return false;
        }
        int i=0,j=0;
        while(i<M && j<N){
            if(a[i]==b[j])
                i++;
            j++;
        }
    return i==M;
    }
    static bool compare (string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        n=words.size();
        vector<int>dp(n,1);
        int maxl=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxl=max(maxl,dp[i]);
                }
            }
        }
        return maxl;
    }
};