class Solution {
public:
    bool search(vector<int>& a, int target) {
        int l=0,r=a.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(target==a[m])
            return true;
            if(a[l]<=a[m])
            {
                if(target>=a[l] && target<a[m])
                r=m-1;
                else
                l=m+1;
            }
            else
            {
                if(target>a[m] && target<=a[r])
                l=m+1;
                else
                r=m-1;
            }
        }
        return false;
    }
};
