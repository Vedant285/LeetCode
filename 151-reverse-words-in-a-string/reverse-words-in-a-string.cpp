class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
    stack<string> st;
    string temp = "";
    string ans = "";

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            if (!temp.empty())
                st.push(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }

    ans += temp;

    while (!st.empty()) {
        ans += " " + st.top();
        st.pop();
    }

    if (!ans.empty() && ans[0] == ' ')
        ans = ans.substr(1);

    return ans;
    }
};