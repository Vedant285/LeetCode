class Solution {
    vector<int>LeftSmallest(vector<int>& arr,int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                result[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int>RightSmallest(vector<int>& arr,int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                result[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return result;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>LS=LeftSmallest(arr,n);
        vector<int>RS=RightSmallest(arr,n);
        int mod=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-LS[i];
            int right=RS[i]-i;
            long long k=left*right;

            sum=(sum+(arr[i]*k))%mod;
        }
        return sum;
    }
};