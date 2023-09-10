class Solution:
    def countOrders(self, n: int) -> int:
        mod=1e9+7
        if n==1:
            return 1
        result=1
        for i in range(2,n+1):
            space=(i-1)*2+1
            temp=space*(space+1)//2
            result*=temp
            result%=mod
        return int(result)