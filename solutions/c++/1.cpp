//64% speed
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        std::vector<int> answer;
        int compliment=0,index=0;
        while (index < nums.size()+1) {
            compliment=target-nums[index];
            if ((hash.find(compliment) != hash.end()) && (hash[compliment] != index)) {
                answer.insert(answer.begin(), hash[compliment]);
                answer.insert(answer.begin()+1, index);
                return answer;
            }
            else {
            hash[nums[index]]=index;
             index++;
            }
        }
    }
};
