class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string s;
        if(k == 0) return "0";
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 &&  (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k>  0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        while(!s.empty() && s.back() == '0') s.pop_back();
        if(s.empty()) return "0";
        reverse(s.begin(), s.end());
        return s;
    }
};