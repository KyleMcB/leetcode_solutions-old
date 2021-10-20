
//9% speed
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        if (nums.size() == 1) return;
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        int end= nums.size()-1;
        //cout <<
        while (end > 0 and nums[end-1] >= nums[end]) {
            //cout << nums[end-1] << " " << nums[end] << endl;
            end--;
        }
        //cout << nums[end];
        if (end == nums.size()-1) {
            swap(nums[end], nums[end-1]);
        } else if (end == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            end--;
            //find the first one bigger than nums[end] from the right
            int next=nums.size()-1;
            while (nums[next] <= nums[end]) next--;
            swap(nums[end], nums[next]);
            reverse(nums.begin()+end+1, nums.end());
        }
    }
};
//75% speed
//I'm just curios at the performance of the STL to other people's code and my own
//sorry this is a little cheaty
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
