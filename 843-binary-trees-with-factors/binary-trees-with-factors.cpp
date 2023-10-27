class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!=mp.end()){
                    mp[arr[i]]+=mp[arr[j]]*mp[arr[i]/arr[j]];
                }
            }
        }
        int res=0;
        int mod=1e9+7;
        for(auto it:mp){
            res=(res+it.second)%mod;
        }
        return res;
    }
};