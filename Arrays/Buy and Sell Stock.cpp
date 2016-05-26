/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> arr;
        if(prices.size() == 0) return 0;
        int min = prices[0];
        int max_profit = 0;
        for(int i=1; i<prices.size();++i) {
            if(prices[i] < min) {
                min = prices[i];
            } else {
                int profit = prices[i] - min;
                if(profit > max_profit)
                    max_profit = profit;
            }
        }
        return max_profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<int> profits;
       profits.push_back(0);
       
       for(int i = 1; i< prices.size(); i++)
       {
           profits.push_back(prices[i] - prices[i-1]);
       }
       
       int maxsum = 0;
       int maxprofit = 0;
       for(int i = 0; i < profits.size(); i++)
       {
          maxsum += profits[i];   
        if(maxsum > maxprofit)
            maxprofit = maxsum;
        if(maxsum < 0)
            maxsum = 0;
        }
        return maxprofit;
    }
};


// Different implementation without using extra space
