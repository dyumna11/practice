
class Solution {
  public:
  void merge(vector<int>& a, int l, int r,int m)
  {
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
      
  }
    void mergeSort(vector<int>& a, int l, int r) {

        if(l>=r)
        return;
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,r,m);
    }
};
