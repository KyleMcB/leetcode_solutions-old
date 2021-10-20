//%99 speed
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int svsf=prices[0]; //svsf = smallest value so far, like a local min
        int bestprofit=0;

        for (const auto & day : prices) {
            bestprofit=max(bestprofit, day-svsf);
            svsf=min(svsf, day);
        }
        if (bestprofit > 0) {
            return bestprofit;
        }
        return 0;
    }
};
