// RADHE RADHE 
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            int root=arr[i];
            mp[root]=1;
            for(int j=0;j<i;j++){
                int lc=arr[j];
                if(root%lc==0 && mp.find(arr[i]/lc)!=mp.end()){
                    mp[root]+=mp[lc]*mp[arr[i]/lc];
                }
            }
        }
        long long result=0;
        int mod=1e9+7;
        for(auto &it:mp){
            result=(result+it.second)%mod;
        }
        return result;
    }
};