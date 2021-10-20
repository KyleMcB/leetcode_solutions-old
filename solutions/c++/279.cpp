//while this did technically work, its an O(n^2) and didn't pass runtime limit
#if 0
class Solution {
public:
    int numSquares(int n) {
      vector<int> dp(n+1, 0);
      for (int i=1; i*i <= n; i++){
        dp[i*i]=1;
        dp[i*i+1]=2;
      }
      for (int i=1; i <= n; i++) {
        if (dp[i]!=0) {
          dp[i]=dp[i-1]+1;
          int l=1,r=i-1;
          while (l <= r) {
            dp[i]=min(dp[i], dp[l]+dp[r]);
            l++; r--;
          }
        }
      }
      return dp[n];
    }
};
#endif
// after working on this problem some more, I realized that I need to,
// generate the squares then use the minimum coin problem
//18% speed
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (max(n+1, 4), -1);
        for (int i =1; i*i <= n; i++){
          dp[i*i]=1;
        }

        for (int i=0; i<4; i++) {
            dp[i]=i;
        }
        if (dp[n] != -1) return dp[n];
        auto coin_at = [&](int i) {
          if (i < 0) return -1;
          return dp[i];
        };
        for (int i=5; i <=n; i++) {
            if (dp[i] != 1){
              for (int j = 1; (j*j) <= n; j++) {
                if (coin_at(i-(j*j)) != -1) {
                    if (dp[i] == -1) {
                        dp[i] = 1 + coin_at(i-(j*j));
                    } else {
                        dp[i] = min (dp[i], 1 + coin_at(i-(j*j)));
                    }
                }
              }
            }
        }
        return dp[n];
    }
};
