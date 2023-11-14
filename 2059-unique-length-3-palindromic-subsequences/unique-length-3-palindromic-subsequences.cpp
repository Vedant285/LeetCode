class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<pair<int,int>>arr(26,{-1,-1});
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(arr[idx].first==-1)
                arr[idx].first=i;
            arr[idx].second=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int left=arr[i].first;
            int right=arr[i].second;
            if(left==-1){
                continue;
            }
            unordered_set<int>st;
            for(int j=left+1;j<right;j++){
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
    }
};