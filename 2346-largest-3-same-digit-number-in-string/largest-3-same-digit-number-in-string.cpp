class Solution {
public:
    string largestGoodInteger(string num) {
        //int a,b,c;
        int n=num.size();
        if(n<3){
            return "";
        }
        int ans=-1;
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                ans=max(ans,num[i]-'0');
            }
        }
        return ans==-1?"":string(3,'0'+ans);
        
    }
};