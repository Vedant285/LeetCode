class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a = 0, b=0;
        string ans = "";
        while (a < word1.size() && b < word2.size()){
            ans += word1[a++];
            ans += word2[b++];
        }
        while (a < word1.size()){
            ans += word1[a++];
        }
        while (b < word2.size()){
            ans += word2[b++];
        }
        return ans;
        
    }
};