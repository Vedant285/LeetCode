class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string k = "";
        for (auto it : target) {
            k += 'a';
            ans.push_back(k);
            while(k.back() != it) {
                k.back() = (k.back() == 'z') ? 'a' : k.back() + 1;
                ans.push_back(k);
            }    
        }
        return ans;
    }
};