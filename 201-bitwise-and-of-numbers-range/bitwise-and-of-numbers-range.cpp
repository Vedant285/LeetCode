class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //if(log2(left)+1!=log2(right)+1)return 0;
        while(left<right){
            right&=(right-1);
        }
        return right;
    }
};