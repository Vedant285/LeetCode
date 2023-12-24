class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if((i%2==0 && s[i]=='0') ||(i%2 && s[i]=='1'))ans++;
        }
        int n=s.size();
        return min(ans,n-ans);
    }
};