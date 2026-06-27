class Solution {
public:
int merge(int l,int m,int r, vector<int>& a)
{
    int c=0;
    int j=m+1;
    for(int i=l;i<=m;++i)
    {
        
        while(j<=r && a[i]>2LL*a[j])
        ++j;
        c+=(j-(m+1));
    }
    vector<int>temp;
    int left=l,right=m+1;
      while(left<=m && right<=r)
      {
          if(a[left]<=a[right])
          temp.push_back(a[left++]);
          else
          temp.push_back(a[right++]);
      }
      while(left<=m)
      temp.push_back(a[left++]);
      while(right<=r)
      temp.push_back(a[right++]);
      for(int i=l;i<=r;++i)
      a[i]=temp[i-l];
      return c;
      
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
    int reversePairs(vector<int>& a) {
        return mergesort(0,a.size()-1,a);
    }
};
