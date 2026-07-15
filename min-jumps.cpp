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
  class Solution {
  public:

    int minJumps(vector<int>& a) {
        // code here
        int n=a.size();
        vector<int>dp(n,-1);
        if(n == 1)
        return 0;
        if(a[0]==0)
        return -1;
        int l=0,r=0,jumps=0;//range from l to r is accessible
        while(r<n-1)
        {
            int far=r;//initially far=r
            for(int ind=l;ind<=r;++ind)
            {
                far=max(far,a[ind]+ind);//far is the max it can go
            }
            if(far==r)//if far remains same as r then no progress has been made
            return -1;//directly return -1
            l=r+1;//for next iteration l becomes just next to r
            r=far;//and r=far
            ++jumps;
        }
   
      return jumps;
          
    }
};

       
    }
