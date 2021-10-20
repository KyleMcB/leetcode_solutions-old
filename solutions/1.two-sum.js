/*
 * @lc app=leetcode id=1 lang=javascript
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = new Map()
  for (let i = 0; i < nums.length; i++) {
    const compliment = target - nums[i];
    if (map.has(compliment)) {
      // we have the two indices
      return [i, map.get(compliment)]
    } else {
      // didn't find it, add current value to the map
      map.set(nums[i], i)
    }
  }
};
// @lc code=end
