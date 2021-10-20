/*
 * @lc app=leetcode id=7 lang=javascript
 *
 * [7] Reverse Integer
 */

// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  let negative;
  if (x < 0) {
    negative = true
  } else {
    negative = false
  }
  if (negative) {
    x = Math.abs(x)
  }
  let result = 0;
  while (x) {
    result += x % 10;
    result *= 10;
    x = Math.floor(x / 10)
  }
  result /= 10;
  if (negative) {
    result *= -1;
  }
  if (result < -(2 ** 31) || result > 2 ** 31 - 1) {
    return 0;
  }
  return result
};
// @lc code=end
