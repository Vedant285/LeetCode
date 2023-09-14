class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
    vector<string>result;
    void dfs(string s){
        auto &it=adj[s];
        while(!it.empty()){
            string v=it.top();
            it.pop();
            dfs(v);
        }
        result.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets){
            adj[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};