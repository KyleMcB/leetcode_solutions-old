//%30 speed
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        for (int i=L; i <=R; i++) {
            if (isprimelimited(numofones(i)))
                ans++;
        }
        return ans;
    }
    int numofones(int target) {
        //int mask=1;
        int setbits=0;
        for (int mask=1; mask <= target; mask=mask<<1) {
            if (target&mask) setbits++;
        }
        return setbits;
    }
    bool isprimelimited(int target) {
        return (665772 >> target)&1 ;
            //thanks StefanPochmann neat trick
    }

};
