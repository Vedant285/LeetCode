class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int i=1;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int X=points[i-1][0];
            int Y=points[i-1][1];
            res+=(max(abs(x-X),abs(y-Y)));
        }
        return res;
    }
};