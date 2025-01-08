class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
    if (str1.size() > str2.size()) return false;
    return str2.substr(0, str1.size()) == str1 && str2.substr(str2.size() - str1.size()) == str1;
}

    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

    for (int i = 0; i < words.size(); ++i) {

        for (int j = i + 1; j < words.size(); ++j) {

            if (isPrefixAndSuffix(words[i], words[j])) {

                count++;

            }

        }

    }

    return count;
    }
};