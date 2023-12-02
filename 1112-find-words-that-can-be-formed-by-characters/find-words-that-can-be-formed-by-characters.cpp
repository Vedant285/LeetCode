class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        vector<int>c(26,0);
        for(auto it:chars){
            c[it-'a']++;
        }
        for(auto it:words){

            vector<int>v(26,0);
            for(auto s:it){
                v[s-'a']++;
            }
            bool isValid=true;
            for(int i=0;i<26;i++){
                if(v[i]>c[i]){
                    isValid=false;
                    break;
                }
            }
            if(isValid==true){
                ans+=it.size();
            }
        }
        return ans;
    }
};