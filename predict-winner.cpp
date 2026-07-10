class Solution {
public:
int memo(int i,int j,vector<int>&a,vector<vector<int>>&dp)
{
    if(i==j)
    return a[i];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int front=a[i]-memo(i+1,j,a,dp);
    int back=a[j]-memo(i,j-1,a,dp);
    return dp[i][j]=max(front,back);
}
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       return memo(0,n-1,nums,dp)>=0;
    }
};
