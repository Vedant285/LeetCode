class Solution {
public:
    bool kbit(int n, int i){
        return 1 & (n >> i);
    }
    int check(int n) {
        int cnt = 0;
        for(int i=0;i<32;i++) {
            if(kbit(n, i)) cnt++;
        }
        return cnt;
    }
    bool isPowerOfTwo(int n) {
        if(n< 0) return 0;
        return check(n) ==1;
    }
};