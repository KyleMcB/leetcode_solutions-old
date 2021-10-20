/*
 * @lc app=leetcode id=121 lang=javascript
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let localValue = 0, maxValue = 0;
  for (let i = 1; i < prices.length; i++) {
    localValue += prices[i] - prices[i - 1];
    if (localValue < 0) localValue = 0;
    maxValue = Math.max(maxValue, localValue)
  }
  return maxValue
};
// @lc code=end
