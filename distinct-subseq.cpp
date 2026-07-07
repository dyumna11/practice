class Solution {
  public:
 
    int distinctSubseq(string &str) {
        // code here
        int n=str.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        int mod=1e9+7;
        unordered_map<char,int>last;
        for(int i=1;i<=n;++i)
        {
            dp[i]=2*dp[i-1];// all the sub will be doubled, when we add a new char
            char ch=str[i-1];
            if(last.count(ch))//calc last subseq of the repeated char
            {
                dp[i]=(dp[i]-dp[last[ch]-1]+mod)%mod;//last[ch]-1 coz we only want
                //those subseq who were before the prev occ
                //from the total that we got, delete the repeated ones if exist
            }
            last[ch]=i;
        }
        return dp[n];
    }
};
