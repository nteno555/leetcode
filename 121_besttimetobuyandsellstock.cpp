class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int runningMin = prices[0], maxProfit = 0, j=prices.size()-1;

        for (int i=1; i<prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - runningMin);
            runningMin = min(runningMin, prices[i]);
        }

        return maxProfit;
    }
};