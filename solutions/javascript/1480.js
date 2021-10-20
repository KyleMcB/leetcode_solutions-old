/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
  result = []
  result.length = nums.length
  result.push(nums[0])
  for (let i = 1; i < nums.length; i++) {
    result.push(result[i - 1] + nums[i])
    // interesting note: array.push seems much better than array[index] = result
  }
  return result
};
