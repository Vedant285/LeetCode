class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int ones=0;
        for(auto it:s){
            if(it=='1'){
                ones++;
            }
        }
        string ans="";
        for(int i=0;i<n-1;i++){
            if(i<ones-1){
                ans+="1";
            }
            else{
                ans+="0";
            }
        }
        ans+="1";
        return ans;

    }
};