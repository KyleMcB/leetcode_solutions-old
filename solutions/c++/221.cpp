// 79% speed
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        if (matrix.size()==1 && matrix[0][0] == '1') return 1;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        auto min_around = [&dp] (int col, int row) {
            return min(min(dp[col-1][row], dp[col-1][row-1]), dp[col][row-1]);
        };
        int ans=0;
        for (int col =0; col < dp.size(); col++) {
            for (int row = 0; row < dp[0].size(); row++) {
                if (matrix[col][row] == '1') {
                    ans=1;
                    dp[col][row]=1;
                }
            }
        }
        for (int col =1; col < matrix.size(); col++) {
            for (int row =1; row < matrix[0].size(); row ++) {
                if (dp[col][row] > 0) {
                    dp[col][row] = 1 + min_around(col, row);
                    ans = max(ans, dp[col][row]);
                }
            }
        }
        return ans * ans;
    }
};
