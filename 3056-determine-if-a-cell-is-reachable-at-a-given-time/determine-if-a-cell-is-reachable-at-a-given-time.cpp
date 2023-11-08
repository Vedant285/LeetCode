class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        int d=max(x,y);
        return d>0?t>=d:t!=1;
    }
};