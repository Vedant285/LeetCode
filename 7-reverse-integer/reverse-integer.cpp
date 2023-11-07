class Solution {
public:
    int reverse(int x) {
        long ans=0;
        
        if(x<-9 && x>=9)return x;
        while(x){
            int ldx=x%10;
            ans=ans*10+ldx;
            x/=10;
        }
        if(ans>INT_MAX || ans<INT_MIN)return 0;
        return ans;
    }
};