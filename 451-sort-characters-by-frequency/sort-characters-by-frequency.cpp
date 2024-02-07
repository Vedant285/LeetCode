class Solution {
public:
    string frequencySort(string s) {
        multimap<int,char>pq;
        string ans="";
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        
        for(auto it:mp){
            pq.insert({it.second,it.first});
        }
        for(auto it=pq.rbegin();it!=pq.rend();it++){
            //for(int i=0;i<it.second;i++){
                ans+=string(it->first,it->second);
            //}
        }
        return ans;
    }
};