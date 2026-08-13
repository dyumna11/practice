class Solution {
public:
    
    bool possible(int k,int n,int m,vector<vector<int>>&dp)
    {
        int mnrow = n;
        int mxrow = -1;
        int mncol = m;
        int mxcol = -1;

        for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                    {
                        if(dp[i][j]>=k)
                        {
                            int r=i-k+1;
                            int c=j-k+1;
                            mnrow=min(mnrow,r);
                            mxrow=max(mxrow,r);
                            mncol=min(mncol,c);
                            mxcol=max(mxcol,c);
                            
                        }
                    }
            }
         if(mxrow == -1)
            return false;
       return(mxrow-mnrow>=k || mxcol-mncol>=k);
    }
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                    {
                        if(mat[i][j]==1)
                        {
                            if(i==0 || j==0)
                                dp[i][j]=1;
                            else
                              dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                        }
                        mx=max(dp[i][j],mx);
                          
                    }
            }
        for(int k=mx;k>=0;--k)
            {
                if(possible(k,n,m,dp))
                    return k*k;
            }
        return 0;
        
    }
};
