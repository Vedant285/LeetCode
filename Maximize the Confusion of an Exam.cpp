//Maximize the Confusion of an Exam
class Solution {
public:
    int maxConsecutiveAnswers(string answerkey, int k) {
        int i=0,j=0,n=answerkey.size(),result=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[answerkey[j]]++;
            while(min(mp['T'],mp['F'])>k){
                mp[answerkey[i]]--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};
