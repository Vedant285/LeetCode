class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi=0;
        for(auto &it: s){
            if(it=='(')st.push(it);
            if(it==')')st.pop();
            if(maxi<st.size())maxi=st.size();
        }
        return maxi;
    }
};