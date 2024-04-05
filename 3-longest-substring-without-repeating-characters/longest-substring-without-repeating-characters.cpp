class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int n=s.size();
        int l=0,e=0;
        int maxi=0;
        while(e<n){
            if(mp[s[e]]!=-1){
                l=max(l,mp[s[e]]+1);
            }
            maxi=max(maxi,e-l+1);
            mp[s[e]]=e;
            e++;
        }
        return maxi;
    }
};