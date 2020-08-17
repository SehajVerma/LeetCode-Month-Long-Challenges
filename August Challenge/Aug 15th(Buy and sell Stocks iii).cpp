class Solution {
public:
    int solve(vector<int>&prices,int buyOrsell,int index,int k,int dp[][2][3])
    {
        if(index>=prices.size() || k==0)
            return 0;
        if(dp[index][buyOrsell][k]!=-1)
            return dp[index][buyOrsell][k];
        
        int x = 0;
        if(buyOrsell == 0 )
        {
            int buy = solve(prices,1,index+1,k,dp)-prices[index];
            int nobuy = solve(prices,0,index+1,k,dp);
            x = max(buy,nobuy);
        }
        else
        {
            int sell = solve(prices,0,index+1,k-1,dp)+prices[index];
            int nosell = solve(prices,1,index+1,k,dp);
            x = max(sell,nosell);
        }
        return dp[index][buyOrsell][k]=x;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        int dp[n][2][3];
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,2,dp);
    }
};


//Simple Method

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){return 0;}
        int buy1=INT_MIN, sell1=INT_MIN, buy2=INT_MIN, sell2=INT_MIN;

/*
SAME CONCEPT AS MEDIUM:BUY AND SELL STOCKS WITH COOLDOWN PERIOD
buy1: 
Means at a given index we are holding 1 stock. If we are holding stock at given index i, it means we could have bought it at i by selling at i-1, or bought at i-1.
sell1:
Means at given index i, we hold zero stocks. This means, we sold at index i by buying previously, or sold it at i-1 and not bought at i.
*/
        for(auto p: prices){
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1+p);
            buy2=max(buy2, sell1-p);
            sell2=max(sell2, buy2+p);
        }
      return sell2;  
    }
};
