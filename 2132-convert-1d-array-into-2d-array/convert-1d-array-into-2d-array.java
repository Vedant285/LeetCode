class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if(original.length!=m*n){
            return new int[0][0];
        }
        int a=0,b=0;
        int arr[][]=new int[m][n];
        for(int i=0;i<original.length;i++){
            if(b==arr[0].length){
                a++;
                b=0;
            }
            arr[a][b++]=original[i];
        }
        return arr;
        
    }
}