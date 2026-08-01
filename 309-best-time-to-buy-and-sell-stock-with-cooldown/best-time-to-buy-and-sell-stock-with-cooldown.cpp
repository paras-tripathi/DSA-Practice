class Solution {
public:
    int solve(vector<int>& prices,bool flag,vector<vector<int>>& dp,int i, int n){
        if(i>=n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(flag==0){
            return dp[i][flag]= max(-prices[i]+solve(prices,1,dp,i+1,n),solve(prices,0,dp,i+1,n));
        }
        else{
            return dp[i][flag]= max(+prices[i]+solve(prices,0,dp,i+2,n),solve(prices,1,dp,i+1,n));
        }
    } 
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        return solve(prices,0,dp,0,n);
    }
};