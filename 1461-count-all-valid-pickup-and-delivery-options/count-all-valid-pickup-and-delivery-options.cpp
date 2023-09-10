class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        if(n==1){
            return 1;
        }
        long long result=1;
        for(int i=2;i<=n;i++){
            int space=(i-1)*2+1;
            int temp=space*(space+1)/2;
            result*=temp;
            result%=mod;
        }
        return result;
    }
};