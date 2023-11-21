class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,m=0,l=nums.size()-1;
        while(m<=l){
            switch(nums[m]){
                case 0:swap(nums[s++],nums[m++]);
                       break;
                case 1:m++;
                        break;
                case 2:
                        swap(nums[m],nums[l--]);
                        break;
            }
        }
    }
};