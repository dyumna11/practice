
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int N=1e9+7;
        vector<long long>dp(n+1,0);
        dp[1]=1;
        long long share=0;
        for(int days=2;days<=n;++days)
        {
            if(days-delay>=1)
            share=(share+dp[days-delay])%N;//add those who learned delay days ago
            if(days-forget>=1)
            share=(share-dp[days-forget]+N)%N;//substract those who are forgetting this day, necessary to add +N bec it might give -ve
            dp[days]=share;
        }
        long long ans=0;
        for(int i=max(1,n-forget+1);i<=n;++i)//at the end only person who remembers is after n-forget+1 days
        {
            ans = (ans + dp[i]) % N;
        }
        return ans;
    }
