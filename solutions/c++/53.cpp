//%71 speed
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int64_t ans=numeric_limits<int>::min();
        int64_t sum=numeric_limits<int>::min()/2;
        for (int i=0; i < nums.size(); i++) {
            if (sum+nums[i] < nums[i]) {
                sum=nums[i];
            } else {
                sum+=nums[i];

            }
            ans=max(ans, sum);
        }
        return ans;
    }
};
