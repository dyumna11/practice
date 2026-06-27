class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size(),ans=INT_MAX;
        int l=0,r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(a[l]<=a[m])
            {
            ans=min(ans,a[l]);
            l=m+1;
        }
        else
        {
           ans=min(ans,a[m]);
           r=m-1;
        }
        }
        return ans;
    }
};
