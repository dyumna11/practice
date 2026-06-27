
  int merge(int l,int m,int r,vector<int>& a)
  {
      vector<int>temp;
      int ans=0;
      int left=l,right=m+1;
      while(left<=m && right<=r)
      {
          if(a[left]<=a[right])
          temp.push_back(a[left++]);
          else
          {
              ans+=(m-left+1);
              temp.push_back(a[right++]);
          }
      }
      while(left<=m)
       temp.push_back(a[left++]);
       while(right<=r)
        temp.push_back(a[right++]);
        for(int i=l;i<=r;++i)
        {
            a[i]=temp[i-l];
        }
        return ans;
  }
     int mergesort(int l,int r,vector<int>& a)
{
    if(l>=r)
    return 0;
    int m=l+(r-l)/2;
    int c=0;
    c+=mergesort(l,m,a);
    c+=mergesort(m+1,r,a);
    c+=merge(l,m,r,a);
    return c;
}
    int inversionCount(vector<int> &a) {
        // Code Here
        return mergesort(0,a.size()-1,a);
  
    }
