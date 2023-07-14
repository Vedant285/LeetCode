//Longest Arithmetic Subsequence of Given Difference solution

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp;
        int n=arr.size();
        int result=0;
        for(int i=0;i<n;i++){
            int curr=arr[i]-difference;
            int prev=mp[curr]+1;
            mp[arr[i]]=prev;
            result=max(result,mp[arr[i]]);
        }
        return result;
    }
};
