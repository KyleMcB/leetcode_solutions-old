//100% speed
class Solution {

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size()==1){
            if (target == nums[0]) return 0;
            else return -1;
        }
        //I need a lamdba compare function that simulates an +/- infinity
        int inf=0;
        auto lessthan = [&inf] (int a, int b) {
            //inf=0 is normal lessthan, inf=1 is negative inf and inf=2 is pos inf
            if (inf == 1) {
                //a is -inf so its less
                return true;
            } else if (inf == 2) {
                //a is inf so its more
                return false;
            } else {
                return a < b;
            }
        };
        int start=0, end=nums.size()-1,mid=(end+1)/2;
        cout << start<< " " << mid << " " << end << endl;
        while (start <= end) {
            if (nums[mid] == target) {
                return mid;
            }
            //same side?
            //cout << (nums[mid] < nums[0]) << " " << (target < nums[0]) << endl;
            if ((nums[mid] < nums[0]) == (target < nums[0])) {
                //we are on the same side and should binary search like usual
                inf=0;
            } else {
                //we are on the wrong side
                if (target < nums[0]) {
                    //cout << "neg\n";
                    inf=1;
                } else {
                    //cout << "pos\n";
                    inf=2;
                }
            }
            //now use a normal binary search
            if (lessthan(nums[mid],target)) {
                start=mid+1;
                //cout << "less\n";
            } else {
                //cout << "more\n";
                end = mid-1;
            }
            mid=(start+end+1)/2;
            //cout << start<< " " << mid << " " << end << endl;
        }
        return -1;
    }
};
