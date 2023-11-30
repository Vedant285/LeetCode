class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res=0;
        vector<long long>bit(31,0);
        bit[0]=1;
        for(int i=1;i<=30;i++){
            bit[i]=2*bit[i-1]+1;
        }
        int sign=1;
        for(int i=30;i>=0;i--){
            int s=((1<<i)&n);
            if(s==0){
                continue;
            }
            if(sign>0){
                res+=bit[i];
            }else{
                res-=bit[i];
            }
            sign=sign*-1;
        }
        return res;
    }
};