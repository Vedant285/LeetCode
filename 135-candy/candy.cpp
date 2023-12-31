class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>left(n,1);
        int count=0;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=max(left[i],left[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                left[i]=max(left[i],left[i+1]+1);
            }
        }
        for(int i=0;i<n;i++){
            count+=left[i];
        }
        return count;
    }
};