class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>s1(26,0),t1(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            s1[s[i]-'a']++;
            t1[t[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=ans+abs(s1[i]-t1[i]);
        }
        return ans/2;
    }
};