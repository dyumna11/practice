int Solution::solve(vector<int> &A, int B)
 {
    int n=A.size(),mnleft=INT_MAX,mxright=INT_MIN,i=0,ans=0;
   while(i<n)
   {
       int left=max(0,i-B+1);
       int right=min(n-1,i+B-1);
       int pos=-1;
       for(int j=right;j>=left;--j)
       {
           if(A[j]==1)
           {
               pos=j;
               break;
           }
       }
       if(pos==-1)
       return -1;
       ans++;
       i=pos+B;
       
   }
   return ans;
    
}
