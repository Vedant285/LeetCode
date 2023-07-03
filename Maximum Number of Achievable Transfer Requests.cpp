class Solution {
    void helper(int i,vector<vector<int>>&req,vector<int>&arr,int n,int& ans,int count){
        if(i==req.size()){
            for(auto it:arr){
                if(it!=0)return ;
            }
            ans=max(ans,count);
            return ;
        }
        arr[req[i][0]]++;
        arr[req[i][1]]--;
        helper(i+1,req,arr,n,ans,count+1);
        arr[req[i][0]]--;
        arr[req[i][1]]++;
        helper(i+1,req,arr,n,ans,count);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>arr(n,0);
        int ans=0;
        helper(0,requests,arr,n,ans,0);
        return ans;
    }
};
