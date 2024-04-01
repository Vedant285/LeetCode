class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        bool check=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                check=true;
                len++;
            }
            else if(check){
                break;
            }
        }
        return len;
    }
};