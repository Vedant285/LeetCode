class Solution {
public:
    int maxPower(string s) {
        int ans=0;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i]==s[i-1]){
                curr++;
            }
            else{
                curr=1;
            }
            ans=max(curr,ans);
        }
        return ans;
    }
};