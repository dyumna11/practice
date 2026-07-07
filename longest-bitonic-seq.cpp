class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &a) {
        // code here
        int ans=0;
        vector<int>left(n,1),right(n,1);
        for(int i=0;i<n;++i)
        {
            for(int prev=0;prev<i;++prev)
            {
                if(a[prev]<a[i])
                left[i]=max(left[i],1+left[prev]);
            }
        }
        for(int i=n-1;i>=0;--i)
        {
            for(int prev=n-1;prev>=i;--prev)
            {
                if(a[i]>a[prev])
                right[i]=max(right[i],1+right[prev]);
            }
        }
        for(int i=0;i<n;++i)
        {
            if(left[i] > 1 && right[i] > 1)
            ans=max(ans,right[i]+left[i]-1);
        }
        return ans;
    }
};
