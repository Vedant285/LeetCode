class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int maxi=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        //vector<int>ans(n);
        arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if((arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};