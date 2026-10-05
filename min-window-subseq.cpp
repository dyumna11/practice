class Solution {
public:
int memo(int i,int j, string&s,string&t,vector<vector<int>>&dp)
{
    if(t.size()==j)
    return 0;
    if(s.size()==i)
    return 1e9;
    if (dp[i][j] != -1) return dp[i][j];
int ans=INT_MAX;
    int np=0,p=0;
    if(s[i]==t[j])
        ans= min(ans,1+memo(i+1,j+1,s,t,dp));
    else
     ans=min(ans,1+memo(i+1,j,s,t,dp));
    return dp[i][j]=ans;
}
    string minWindow(string s1, string s2) {
        // User code goes here
        int l=0,n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mn=1e9,start=0;
        for(int i=0;i<n;++i)
        {
           if(s1[i]==s2[0])
           {
            int len=memo(i,0,s1,s2,dp);
            if(len<mn)
            {
                mn=len;
                start=i;
            }
           }
        }
        if(mn==1e9)
return "";
return s1.substr(start,mn);

    }
};
------------------------------------

    string minWindow(string s1, string s2) {
        // User code goes here
        int l=0,n=s1.size(),m=s2.size();
        int i=0,j=0,start=0,mn=1e9;
        while(i<n)
        {
            if(s1[i]==s2[j])
            ++j;
            if(j==m)
            {
                --j;
                int end=i;
                while(j>=0)
                {
                    if(s1[i]==s2[j])
                    --j;
                    --i;
                }
                ++i;
                j=0;
                if(mn>end-i+1)
                {
                    mn=end-i+1;
                    start=i;
                }
            }
            ++i;
        }
        if(mn==1e9)
        return "";
        return s1.substr(start,mn);
    }
};

