/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // null check
        int len = prices.size();
        if (len==0) return 0;

        
        vector<int> historyProfits;
        vector<int> futureProfits;
        int profitOnHistory = prices[0];
        int profitOnFuture = prices[prices.size()-1];
        int maxProfit = 0;
        historyProfits.assign(prices.size(),0);
        futureProfits.assign(prices.size(),0);
        for(int i = 0; i < prices.size(); i++)
        {
            profitOnHistory = min(profitOnHistory, prices[i]);
            if(i > 0)
                historyProfits[i] = max(historyProfits[i-1], prices[i] - profitOnHistory);
        }
        
        for(int i = prices.size() -1; i >= 0; i--)
        {
            profitOnFuture = max(profitOnFuture, prices[i]);
            if(i <  prices.size() -1)
                futureProfits[i] = max(futureProfits[i+1], profitOnFuture - prices[i]);
            
            maxProfit = max(maxProfit, historyProfits[i] + futureProfits[i]);
        }
        return maxProfit;
    }
};