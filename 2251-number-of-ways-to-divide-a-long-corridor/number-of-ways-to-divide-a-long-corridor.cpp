class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.length();
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                idx.push_back(i);
            }
        }
        if(idx.size()%2!=0 || idx.size()==0){
            return 0;
        }
        int mod=1e9+7;
        long long res=1;
        long long end=idx[1];
        for(int i=2;i<idx.size();i+=2){
            int pos=idx[i]-end;
            res=(res*pos)%mod;
            end=idx[i+1];
        }
        return res;
    }
};