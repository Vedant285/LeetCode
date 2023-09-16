class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty()){

            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int x=it.second.first;
            int y=it.second.second;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 ){
                    int diff=abs(heights[x][y]-heights[nr][nc]);
                    int maxi=max(wt,diff);

                    if(result[nr][nc]>maxi){
                        result[nr][nc]=maxi;
                        pq.push({maxi,{nr,nc}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};