class Solution {
public:
    static bool compare(int a,int b){
        int aBit=__builtin_popcount(a);
        int bBit=__builtin_popcount(b);
        if(aBit==bBit){
            return a<b;
        }
        return aBit<bBit;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};