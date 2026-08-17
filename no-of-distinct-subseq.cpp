class Solution {
  public:
 
    int distinctSubseq(string &str) {
        // code here
        int n=str.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        vector<int>last(26,-1);
       for(int i=1;i<=n;++i)
       {
           char ch=str[i-1];
           if(last[ch-'a']==-1)
           dp[i]=2*dp[i-1];
           else
           dp[i]=2*dp[i-1]-dp[last[ch-'a']];
           last[ch-'a']=i-1;
       }
       return dp[n];
    }
};
