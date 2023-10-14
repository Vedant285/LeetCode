class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rMax(n);
        vector<int>lMax(n);
        rMax[0]=height[0];
        for(int i=1;i<n;i++){
            rMax[i]=max(rMax[i-1],height[i]);
        }
        lMax[n-1]=height[n-1];
        int k=0;
        for(int i=n-2;i>=0;i--){
            lMax[i]=max(lMax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(rMax[i],lMax[i])-height[i];
        }
        return ans;
    }
};