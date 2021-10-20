//100% speed w00t!!!
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        array<int,366> dp;
        dp.fill(0);
        auto get_dp = [&](int i) {
            if (i <0 ) return 0;
            return dp[i];
        };
        int d1t=costs[0], d7t=costs[1], d30t=costs[2];
        int last=0;
        for (int i =0; i < days.size(); i++) {
          for (int j=last+1; j < days[i]; j++) {
            dp[j]=get_dp(j-1);
          }
          dp[days[i]]=d1t + get_dp(days[i]-1);
          dp[days[i]]=min(dp[days[i]], d7t + get_dp(days[i]-7));
          dp[days[i]]=min(dp[days[i]], d30t + get_dp(days[i]-30));
          last=days[i];
        }
        return dp[*days.rbegin()];
    }
};
