//spedd 92%
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        auto cva = [&](int i) {
          if (i < 0)
            return numeric_limits<int>::max();
            return dp[i];
        };
        for (int i=1; i < dp.size(); i++) {
          int min=numeric_limits<int>::max();
          for (auto const & coin : coins) {
            if ( cva(i-coin) < min) min = cva(i-coin);
          }
          if (min < numeric_limits<int>::max()) min++;
          dp[i]=min;
        }
        if (dp[amount] == numeric_limits<int>::max()) {
          return -1;
        }
        return dp[amount];
    }
};
