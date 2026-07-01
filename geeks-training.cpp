
  int memo(int day,int last,vector<vector<int>>& a,vector<vector<int>>&dp)
   {
       int mx=0;
       if(day==0)
       {
          for(int tasks=0;tasks<3;++tasks)
       {
           if(tasks!=last)
           {
               mx=max(mx,a[0][tasks]);
           }
       }
       return  dp[day][last]=mx;
       }
       if( dp[day][last]!=-1)
       return  dp[day][last];
       for(int tasks=0;tasks<3;++tasks)
       {
           if(tasks!=last)
           {
               mx=max(mx,a[day][tasks]+memo(day-1,tasks,a,dp));
           }
       }
       return dp[day][last]=mx;
   }
    int maximumPoints(vector<vector<int>>& mat)
    {
          int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
      
       return memo(n-1,3,mat,dp);
    }
