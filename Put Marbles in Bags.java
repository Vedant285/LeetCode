// Put Marbles in Bags solution

class Solution {
    public long putMarbles(int[] weights, int k) {
        long left=0,right=0;
        int n=weights.length;
        int m=n-1;
        int arr[]=new int[m];
        for(int i=0;i<n-1;i++){
            arr[i]=weights[i]+weights[i+1];
        }
        Arrays.sort(arr);
        for(int i=0;i<k-1;i++){
            left+=arr[i];
            right+=arr[m-i-1];
            
        }
        return right-left;
    }
  }
