class Solution {
public:
int memo(int i,int j,string &s,string&t,vector<vector<int>>&dp)
{
    if(j==t.size())
    return 1;
    if(i==s.size())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==t[j])
    {
        int take=memo(i+1,j+1,s,t,dp);
        int nottake=memo(i+1,j,s,t,dp);
        return dp[i][j]=take+nottake;
    }
    else
    {
        int nottake=memo(i+1,j,s,t,dp);
        return dp[i][j]=nottake;
    }

}
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return memo(0,0,s,t,dp);
    }
};
