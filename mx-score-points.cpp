class Solution {
  public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size(),tot=0,s=0,l=0,mn=INT_MAX;
         for(int i=0;i<n;++i)
            tot+=a[i];
        for(int i=0;i<n;++i)
        {
            s+=a[i];
            while(i-l+1>n-k)
            {
                s-=a[l];
                ++l;
            }
            if(i-l+1==n-k)
           mn=min(mn,s);
        }
        return tot-mn;
    }
};
