//speed 67%
class Solution {
public:
    int findMaxForm(vector<string>const & strs, int m, int n) {
        //when finding the maximum amount of way to do something we start at the bottom right of the DP cache rectangle
        array<array<int, 101>, 101> dp;
        for_each(dp.begin(), dp.end(),[](auto& row) {row.fill(0);});
        for (auto const & coin : strs) {
            //each string is like a coin in the change making algo
            int ones = count_if(coin.begin(),coin.end(),[](char const digit){ return digit == '1';});
            int zeros = coin.size()-ones;
            for (int col = n; col >= ones; col--) {
                for (int row = m; row >= zeros; row--) {
                    dp[col][row]= max(dp[col][row], 1+dp[col - ones][row - zeros]);
                }
            }
        }
        return dp[n][m];
    }
};
