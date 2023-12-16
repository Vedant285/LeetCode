class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            int sK=s[i]-'a';
            int tK=t[i]-'a';
            arr[sK]++;
            arr[tK]--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]){
                return false;
            }
        }
        return true;

    }
};