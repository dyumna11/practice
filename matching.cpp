#include <iostream>
#include <vector>
using namespace std;
int ans=0;
int memo(int mask,int n,vector<vector<int>>&a,vector<int>&dp)
{
    if(__builtin_popcount(mask)==n)
        return 1;
    if(dp[mask]!=-1)
        return dp[mask];
    int ways=0;
    int i = __builtin_popcount(mask);
    const int N=1e9+7;
  //we fix the men and we can calculate by using no. of 1s
  //then for each man we find the no of women that can be placed
    for(int j=0;j<n;++j)
    {
        if(mask&(1<<j))
            continue;
        if(a[i][j]==0)
            continue;
        ways=(ways+memo(mask|(1<<j),n,a,dp))%N;
    }
    return dp[mask]=ways;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    vector<int>dp(1<<n,-1);
    cout<< memo(0,n,a,dp);
    
}
   
    

