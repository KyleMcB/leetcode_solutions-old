//98% speed
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+3, 0);
        for (auto i =0; i < cost.size(); i+=1) {
            // auto cost_at_step = cost[i];

            dp[i+2] = min(dp[i],dp[i+1])+cost[i];
        }
        auto end = dp.size()-1;
        dp[end] = min(dp[end-2],dp[end-1]);
        return dp[end];

    }
};
