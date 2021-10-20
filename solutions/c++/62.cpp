// 54% speed
class Solution {
public:
    int uniquePaths(int m, int n) {
        // array<array<int, 101>, 101> dp;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        // for_each(dp.begin(), dp.end(),[](auto & col){col.fill(1);});
        for (int row =1; row < m; ++row) {
            for (int col=1; col <n; ++col) {
                dp[row][col]=dp[row-1][col]+dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};
