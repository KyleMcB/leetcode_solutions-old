//4ms
class Solution {
public:
    constexpr int climbStairs(int n) {
        //I think this is fibanocci
        long n0{1}, n1{1};
        for (int i=0; i< n; ++i) {
            const long next = n1 + n0;
            n0= n1;
            n1= next;
        }
        return n0;
    }
};
