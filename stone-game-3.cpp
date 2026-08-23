class Solution {
public:
int memo(int i,vector<int>&a,vector<int>&dp)
{
     int n=a.size();
    if(i>=n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int ans=INT_MIN,take=0;
   
    for(int x=1;x<=min(3,n-i);++x)
    {
         take += a[i + x - 1];
        int opp=memo(i+x,a,dp);
        ans=max(ans,take-opp);//storing the diff
    }
   return dp[i]=ans;//final diff
}
    string stoneGameIII(vector<int>& stone) {
        
        int n=stone.size();
        vector<int>dp(n+1,-1);
       int ans= memo(0,stone,dp);
       if(ans>0)
       return "Alice";
       else if(ans<0)
       return "Bob";
       else
       return "Tie";
    }
};
