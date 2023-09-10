class Solution {
    public int countOrders(int n) {
        int mod=1000000007;
        if (n==1)return 1;
        long result=1;
        for(int i=2;i<=n;i++){
            int s=(i-1)*2+1;
            int temp=s*(s+1)/2;
            result*=temp;
            result%=mod;
        }
        return (int)result;
    }
}