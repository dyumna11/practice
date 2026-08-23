class Solution {
public:
int memo(int i,int &m, vector<int>&a, vector<vector<int>>&dp,vector<int>&suffix)
{
    int n=a.size();
    if(i>=n)
    return 0;
    if(dp[i][m]!=-1)
    return dp[i][m];
    int mx=0,newm=0,ans=0;
    int total=suffix[i];//remaining piles sum
    for(int x=1;x<=min(2*m,n-i);++x)
    {
        newm=max(m,x);
        mx=memo(i+x,newm,a,dp,suffix);//calc opponent score
        ans=max(ans,total-mx);//take their max
    }
     return dp[i][m]=ans;
}
    int stoneGameII(vector<int>& piles) {
        int m=1,n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suffix(n + 1, 0);
        for(int i=n-1;i>=0;--i)
        {
            suffix[i]=suffix[i+1]+piles[i];//we can see how many scores are left, witht he help of this we can calcu diff
        }
       return memo(0,m,piles,dp,suffix);
    }
};
