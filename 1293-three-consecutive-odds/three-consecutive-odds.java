class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int n=arr.length;
        int k=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1)
                k++;
            else 
                k=0;
            if(k>=3)
                return true;
            

        }
        return false;
    }
}