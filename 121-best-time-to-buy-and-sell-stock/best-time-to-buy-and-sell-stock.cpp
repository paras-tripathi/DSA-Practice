class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int buy=prices[0];
        for(int value:prices){
            buy=min(buy,value);
            profit=max(profit,value-buy);
        }
        return profit;
    }
};