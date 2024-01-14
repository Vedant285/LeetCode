class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m)return false;
        vector<int>countA(26),countB(26);
        for(int i=0;i<n;i++){
            countA[word1[i]-'a']++;
            countB[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if((countA[i]!=0 &&countB[i]==0) || (countA[i]==0 &&countB[i]!=0) )return false;
        }
        sort(countA.begin(),countA.end());
        sort(countB.begin(),countB.end());
        for(int i=0;i<26;i++){
            if(countA[i]!=countB[i])return false;
        }
        return true;
        
    }
};