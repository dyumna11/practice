class Solution {
public:
int memo(int idx,int d, vector<vector<int>>&dp,vector<int>& nums)
{
    int mx=0,res=0,ans=INT_MAX;
     int n=nums.size();
    if(d==1)
    {
        for(int i=idx;i<n;++i)
        mx=max(nums[i],mx);
        return mx;
    }
    
    if(dp[idx][d]!=-1)
    return dp[idx][d];
    for(int i=idx;i<=n-d;++i)
    {
        mx=max(mx,nums[i]);
        res=mx+memo(i+1,d-1,dp,nums);
        ans=min(ans,res);
    }
    return dp[idx][d]=ans;
}
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(n<d)
        return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
       return memo(0,d,dp,job);
    }
};
