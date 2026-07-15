 int memo(int i,vector<int>& arr,vector<int>& dp)
  {
      int mn=INT_MAX,n=arr.size();
      if(i==n-1)
      {
          return 0;
      }
      if(arr[i]==0)
      return INT_MAX;
      if(dp[i]!=-1)
      return dp[i];
      for(int ind=i+1;ind<=min(i+arr[i],n-1);++ind)
      {

          int temp=memo(ind,arr,dp);
          if(temp!=INT_MAX)
           mn=min(mn,1+temp);
      }
      return dp[i]=mn;
  }
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,-1);
        if(arr[0]==0)
        return -1;
        if(n == 1)
    return 0;
       int ans= memo(0,arr,dp);
       if(ans==INT_MAX)
       return -1;
       return ans;
    }
//tc= O(n*n) fails for 1e5
//-------------------------------------------------------------
//greedy O(N)
    int minJumps(vector<int>& a) {
        // code here
        int n=a.size();
        if(n == 1)
        return 0;
        if(a[0]==0)
        return -1;
        
       int ans=INT_MAX;
       int jumps=1;
       int stepend=a[0],mxreach=a[0];
       for(int i=1;i<n;++i)
       {
           if(i==n-1)
           return jumps;
            mxreach=max(mxreach,a[i]+i);
           if(i==stepend)
           {
                if(i>=mxreach)
           return -1;
               ++jumps;
               stepend=mxreach;
               if(stepend>=n-1)
               return jumps;
           }
          
       }
       return -1;
       
    }
