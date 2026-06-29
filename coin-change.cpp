
    int coin(int s,
             vector<int>& dp,
             vector<int>& a)
    {
        if(s < 0)
            return 1e9;
        if(s == 0)
            return 0;
        if(dp[s] != -1)
            return dp[s];

        int mn = 1e9;

        for(int i = 0; i < a.size(); ++i)
        {
            mn = min(mn,
                     1 + coin(s - a[i],
                              dp,
                              a));
        }

        return dp[s] = mn;
    }

    int coinChange(vector<int>& a,
                   int amount)
    {
        vector<int> dp(amount + 1, -1);

        int ans =
            coin(amount, dp, a);

        return (ans >= 1e9)
               ? -1
               : ans;
    }
