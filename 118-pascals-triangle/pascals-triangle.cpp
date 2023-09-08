class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pas(numRows);
        for(int i=0;i<numRows;i++){
            pas[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                pas[i][j]=pas[i-1][j]+pas[i-1][j-1];
            }
        }
        return pas;
    }
};