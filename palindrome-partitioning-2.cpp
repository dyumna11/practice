

    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=2)
                    pal[i][j]=true;
                    else
                    pal[i][j]=pal[i+1][j-1];
                }
            }
        }
        for(int i=n-1;i>=0;--i)
        {
            int ans=1e9;
            for(int j=i;j<n;++j)
            { 
                if(pal[i][j])
                ans=min(ans,1+dp[j+1]);
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
