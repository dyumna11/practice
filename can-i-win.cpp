class Solution {
public:
int sum=0;
int memo(int mask,int sum,int total,int mx, vector<int>&dp)
{
    if(dp[mask]!=-1)
    return dp[mask];
    for(int i=1;i<=mx;++i)
    {
        if((1<<i)&mask)
        continue;
        if(sum+i>=total)//if player 1 canw in, set to true
        
        return dp[mask]=true;
        if(!memo(mask|(1<<i),sum+i,total,mx,dp))//for next chance, if player 2 cannot win then only set to true
       return dp[mask]=true;
    }
    return dp[mask]=false;
}
    bool canIWin(int mx, int total) {
        int n=1<<(mx+1);
        if (mx * (mx + 1) / 2 < total)
            return false;
        vector<int>dp(n,-1);
        return memo(0,0,total,mx,dp);
    }
};
//tc= 2^mx(ubstes) * mx
