//4ms runtime
class Solution {
    set<int> seen;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        int next=0;
        while (n>=10) {
            int digit=n%10;
            //cout << "digit " << digit<< endl;
            next+=digit*digit;
            n/=10;
        }
        //cout << "digit " << n<< endl;
        next+=n*n;
        //if (next == 1) return true;
        //cout << next << endl;
        if (seen.count(next) > 0) {
            return false;
        } else {
            seen.insert(next);
        }
        return isHappy(next);
    }
};
