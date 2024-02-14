class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0,neg=1;
        vector<int>a(n);
        for(auto it:nums){
            if(it>=0){
                a[pos]=it;
                pos+=2;
            }
            else{
                a[neg]=it;
                neg+=2;
            }
        }
        return a;
    }
};