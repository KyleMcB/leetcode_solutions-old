//speed %88
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        dp[0]=A[0];//just copy the first row;
        for (int row=1; row < A.size(); row++) {
            for (int col=0; col < A.size(); col++) {
                //dp[row][col]= set to straight above then check sides
                dp[row][col]=dp[row-1][col];
                if (col-1 >= 0){
                    dp[row][col]= min(dp[row][col],dp[row-1][col-1]);
                }
                if (col+1 < A.size()){
                    dp[row][col]=min(dp[row][col],dp[row-1][col+1]);
                }
                dp[row][col]+=A[row][col];
            }
        }
        return *min_element(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
    }
};
