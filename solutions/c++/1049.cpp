//83% speed
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // we need a grid of bools size nm where n= stones.size, m= sum of all stone weights
        int m = accumulate(stones.begin(), stones.end(),0);
        int n = stones.size();
        vector<vector<bool>> dp (n, vector<bool>(m, false));
        //we set the first col true at the weight of the first stone, this is its difference with it self
        dp[0][stones[0]]=true;
        for (int col =0; col < n-1; col+=1) {
            for (int row=0; row < m; row+=1) {
                //was the previous stone difference a possability?
                //if so mark changes in differences
                if (dp[col][row]) {
                    dp[col+1][row+stones[col+1]]=true;
                    if (row - stones[col+1] >= 0) {
                        dp[col+1][row - stones[col+1]]=true;
                    } else {
                        dp[col+1][stones[col+1] - row]=true;
                    }
                }
            }
        }
        for (auto i=0; i < m; i++) {
            if (dp[n-1][i]) return i;
        }
        return m;
    }
};
