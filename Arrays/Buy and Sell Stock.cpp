/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.


*/

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

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() < 1)
            return 0;
        int smallestprice = prices[0];    
        int smallestIndex = 0;         
        for(int i = 1; i < prices.size() - 1; i++)
        {
            if(smallestprice > prices[i])
            {
                smallestprice = prices[i];
                smallestIndex = i;
            }
        }
        int largestprice = prices[smallestIndex];
        for(int i = smallestIndex+ 1; i < prices.size(); i++)
        {
            largestprice = max(largestprice, prices[i]);
        }
        int forwardprofit = largestprice -smallestprice;
        
        largestprice = prices[prices.size() - 1];
        int largestindex = prices.size() -1;
        for(int i = prices.size() - 1; i > 0; i--)
        {
            if(largestprice < prices[i])
            {
                largestprice = prices[i];
                largestindex = i; 
            }
        }
        smallestprice = prices[0];
        
        for(int i = 0; i < largestindex; i++)
        {
            smallestprice = min(smallestprice, prices[i]);
        }
        int backwardprofit = largestprice - smallestprice;
        
        int maxprofit = max(forwardprofit, backwardprofit);
        
         
        return maxprofit;
    }
};