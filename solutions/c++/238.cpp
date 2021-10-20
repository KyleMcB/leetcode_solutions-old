//%84 speed
//V. 2 DP style
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto size = nums.size();
        if (size == 0) return {};
        if (size == 1) return {1};
        if (size == 2) return {nums[1], nums[0]};
        vector<int> ans(size,1);
        vector<int> fromleft(size,1);
        vector<int> fromright(size,1);
        //fromleft loop
        auto left= fromleft.begin()+1;
        for (auto index = nums.begin()+1; index != nums.end(); index++) {
            *left= *(left-1) * *(index-1);
            left++;
        }

        auto right= fromright.rbegin()+1;
        for (auto index = nums.rbegin()+1; index != nums.rend(); index++) {
            *right= *(right-1) * *(index-1);
            right++;
        }

        for (int index = 0; index < ans.size(); index++) {
            ans[index]= fromleft[index] * fromright[index];
        }
        return ans;
    }
};
