class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string k="";
    for(auto i:word1 )
    {
        k+=i;
    }
    string j="";
    for(auto i:word2 )
    {
        j+=i;
    }
    return k==j;
     
    }
};