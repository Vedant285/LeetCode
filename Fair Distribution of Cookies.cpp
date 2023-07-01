class Solution {
public:
    int n;
    int result=INT_MAX;
    void solve(int ind,vector<int>&cookies,vector<int>&child,int k){
        if(ind>=n){
            int unf=*max_element(child.begin(),child.end());
            result=min(result,unf);
            return ;
        }
        int cok=cookies[ind];
        for(int i=0;i<k;i++){
            child[i]+=cok;
            solve(ind+1,cookies,child,k);
            child[i]-=cok;

        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int>child(k,0);
        
        solve(0,cookies,child,k);
        return result;
        
    }
};
int main(){
     vector<int>cookies= [8,15,10,20,8];
    int k=2;
    Solution s;
    cout<<s.distributeCookies(cookies,k);
}
