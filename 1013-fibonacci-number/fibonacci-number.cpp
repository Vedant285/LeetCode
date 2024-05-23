
#define ll long long
class Solution {
public:
    int fib(int n) {
        ll a = pow((1+sqrt(5)),n);
        ll b = pow((1-sqrt(5)),n);
        ll c = pow(2,n) * (sqrt(5));
        return (a-b)/c;
    }
};